import java.io.*;
import java.net.*;
import java.util.*;

import java.awt.BorderLayout;
import java.awt.Menu;
import java.awt.MenuBar;
import java.awt.MenuItem;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.ScrollPaneConstants;

//--------------------------------------------------------------//
//程式流程
//---Server  --主類別檔
//1. main  --主程式進入點
//2. go()   --方法  --建位連線  --等待請求連線
//     --取得連線後往下執行
//3. Process  --內部類別 --處理程序
//3.1. Process  --建構子 --由執行緒呼叫 --建立接收
//3.2. run()  --方法  --執行執行緒
//3.3. tellApiece() --方法  --告訴每人
//--------------------------------------------------------------//
//Server主類別檔(後臺執行)
//--------------------------------------------------------------//

@SuppressWarnings("serial")
//直接在class內extends物件JFrame後便可直接寫入視窗程式
public class Server extends JFrame implements ActionListener
{
	Vector<PrintStream> output; //output存取向量空間
	
	//--------------------------------------------------------------//
	//1. 主程式進入點
	//--------------------------------------------------------------//
	public static void main(String args[]) 
	{
		new Server().go(); //開始程式
	}
	
	//--------------------------------------------------------------//
	//2. 建位連線
	//--------------------------------------------------------------//
	public void go() 
	{
	    output = new Vector<PrintStream>(); //建立物件陣列
	    try 
	    {
	    	//產生ServerSocket設定port:10000(依題目要求)
	    	@SuppressWarnings("resource")
			ServerSocket serverSock = new ServerSocket(10000);
	    	while (true) 
	    	{
		        Socket cSocket = serverSock.accept(); //等待連線的請求--串流
		        
		        //建立I/O管道
		        PrintStream writer = new PrintStream(cSocket.getOutputStream());//透過PrintStream接收資料
		        System.out.println(writer); //取得Socket的輸出資料流(Ex.java.io.PrintStream@291ae)
		        output.add(writer); //元件加入Vector
		        //傳入一個Runnable物件並分派一個新的執行緒
		        Thread start = new Thread(new Process(cSocket)); //建立伺服器主執行緒
		        start.start(); //啟動執行緒
		    }
	    } 
	    catch (Exception ex) 
	    {
	    	System.out.println("伺服器創建失敗port已被占用");
	    	state.setText("伺服器創建失敗port已被占用"); //偵錯用
	    }
	}
	
	//--------------------------------------------------------------//
	//3. Process處理程序 @override
	//--------------------------------------------------------------//
	public class Process implements Runnable 
	{
	    BufferedReader reader; //暫存資料的Buffered
	    Socket sock; //建立一個Socket變數
	    
	    //----------------------------------------------------------//
	    //3.1. 由執行緒呼叫---建立接收
	    //----------------------------------------------------------//
	    public Process(Socket socket)
	    {
	    	try 
	    	{
		        sock = socket; //new一個收資料的socket
		        reader = new BufferedReader(new InputStreamReader(sock.getInputStream()));//取得Socket的輸入資料
	    	} 
	    	catch (Exception ex) 
	    	{
	    		System.out.println("連接失敗Process"); //偵錯用
	    	}
	    }
	    
	    //--------------------------------------------------------------//
	    //3.2. 執行執行緒
	    //--------------------------------------------------------------//
	    public void run() 
	    {
	    	String message;
	    	try 
	    	{
	        //讀取資料
	    		while ((message = reader.readLine()) != null) 
	    		{
	    			System.out.println("收到" + message);
	    			tellApiece(message);
	    		}
	    	} 
	    	catch (Exception ex) 
	    	{
	    		System.out.println("有一個連接離開"); //偵錯用
	    	}
	    }
	    
	    //--------------------------------------------------------------//
	    //3.3. 告訴每人
	    //--------------------------------------------------------------//
	    public void tellApiece(String message) 
	    {
	    	Iterator<PrintStream> it = output.iterator(); //產生iterator可以存取集合內的元素資料
	    	while (it.hasNext()) //向下讀取元件
	    	{
	    		try 
	    		{
	    			PrintStream writer = (PrintStream) it.next(); //取集合內資料
	    			writer.println(message); //印出
	    			writer.flush(); //刷新該串流的緩衝。
	    		} 
	    		catch (Exception ex) 
	    		{
	    			System.out.println("連接失敗Process"); //偵錯用
		        }
	    	}
	    }
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~以上為Server端伺服器架設~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~以下為Server端聊天室基本與Client相同~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	//宣告區
	//設定名子及ip
	Scanner input = new Scanner(System.in);
	String name, ip = "";
	PrintStream writer;
	
	//建立Socket變數
	Socket sock;
	
	//顯示區域
	JTextArea incoming = new JTextArea(15, 50); //build TextArea row:15 column:50
	
	//輸入區域
	JLabel state = new JLabel("電腦網路進階"); //build label
	JLabel NameLabel = new JLabel("使用者名稱："); //build label
	JLabel IPLabel = new JLabel("Server IP："); //build label
	JTextArea sendTextBox = new JTextArea(2, 35); //build TextArea row:2 column:35
	JTextField NameTextBox = new JTextField("Server", 10); //build TextBox
	JTextField IPTextBox = new JTextField("127.0.0.1", 10); //build TextBox
	
	//menu
	MenuBar mBar = new MenuBar(); //創建下拉式選單
	//File
	Menu mFile = new Menu("File"); //檔案選單按鈕
	//SaveFile
	MenuItem mFileSave = new MenuItem("SaveFile"); //存檔案選單按鈕
	  
	Server() //設定及宣告視窗物件
	{
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~對話區域定位在上面~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
		super("Server端");//建立視窗JFrame
		JPanel Build = new JPanel();//用來放name及ip--設定區域
	    JButton setServerIP = new JButton("建立連線");//建來設定按鍵
	    setServerIP.addActionListener(this);//按下設定
	    
	    //名字
	    Build.add(NameLabel);
	    Build.add(NameTextBox);
	    NameTextBox.setEditable(false); //不可修改
	    
	    //IP address
	    Build.add(IPLabel);
	    Build.add(IPTextBox);
	    IPTextBox.setEditable(false); //不可修改
	    
	    //設定ServerIP
	    Build.add(setServerIP);
	    getContentPane().add(BorderLayout.NORTH, Build);
	    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~對話區域定位在上面~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	    
	    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~對話區域定位在中間~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	    JButton sendButton = new JButton("送出"); //JButton("送出")
	    sendButton.addActionListener(this); //按下
	    
	    JButton leave = new JButton("關閉聊天室系統"); //JButton("關閉聊天室系統")
	    leave.addActionListener(this); //按下
	    
	    final JButton selgraph = new JButton("選取圖片"); //JButton("選取圖片")
	    selgraph.addActionListener(this);
	    
	    //設定TextArea
	    incoming.setLineWrap(true); //設置為 true，則當行的長度大於所分派的寬度時，將換行
	    incoming.setWrapStyleWord(true); //設置為 true，則當行的長度大於所分派的寬度時，將在單詞邊界（空白）處換行
	    incoming.setEditable(false); //不可編輯的
	    
	    JScrollPane receive = new JScrollPane(incoming); //接收訊息的JScrollPane
	    receive.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS); //垂直滾動
	    receive.setHorizontalScrollBarPolicy(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER); //水平滾動
	    
	    JScrollPane send = new JScrollPane(sendTextBox); //傳送訊息的JScrollPane
	    send.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS); //垂直滾動
	    send.setHorizontalScrollBarPolicy(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER); //水平滾動
	    
	    JPanel mainPanel = new JPanel(); //放置按鈕
	    mainPanel.add(receive); //放置對話方塊
	    mainPanel.add(send); //放置文字送出方塊
	    mainPanel.add(sendButton); //放置傳送按鈕
	    mainPanel.add(selgraph); //放置選取圖片
	    mainPanel.add(leave); //離開聊天室按鈕
	    getContentPane().add(BorderLayout.CENTER, mainPanel);
	    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~對話區域定位在中間~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	    
	    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~狀態區域定位在下方~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	    mFileSave.addActionListener(this); //Menu事件
	    mFile.add(mFileSave); //加入MenuItem
	    mBar.add(mFile); //加入Menu
	    setMenuBar(mBar); //MenuBar
	    getContentPane().add(BorderLayout.SOUTH, state); 
	    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~狀態區域定位在下方~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	    
	    setSize(600, 480); //視窗大小600x480
	    setVisible(true); //使可見
	    
	    this.addWindowListener(new WindowAdapter() {
	    	public void windowClosing(WindowEvent e) {
    			System.exit(0); //偵測到按下右上角X便結束程式
	    	}
	    });
	}
	
	//--------------------------------------------------------------//
	//3. 建立連線
	//--------------------------------------------------------------//
	
	private void EstablishConnection() //建立連線
	{
	    try 
	    {
	    	sock = new Socket("127.0.0.1", 10000); //NEW一個傳至server的socket預設自己連自己
	    	
	    	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~以下建立I/O資料流~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	    	InputStreamReader streamReader = new InputStreamReader(sock.getInputStream()); //取得Socket的輸入資料流
	    	input = new Scanner(streamReader); //放入暫存區
	    	writer = new PrintStream(sock.getOutputStream()); //取得Socket的輸出資料流
	    	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~以上建立I/O資料流~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	    	
	    	state.setText("網路建立-連線成功"); //左下角狀態顯示
	    } 
	    catch (IOException ex) 
	    {
	    	System.out.println("建立連線失敗"); //偵錯用
	    	state.setText("建立連線失敗，未開啟伺服器");
	    }
	}

	//--------------------------------------------------------------//
	//4. 接收資料
	//--------------------------------------------------------------//

	public class IncomingReader implements Runnable 
	{
		public void run() 
	    {
	    	String message;
	    	try 
	    	{
	    		while ((message = input.nextLine()) != null ) //先做讀取input在判斷是否為空
	    			incoming.append(message + '\n'); //接收訊息TextBox送出之訊息
	    	} 
	    	catch (Exception ex)
	    	{
	    		ex.printStackTrace();
	    	}
	    }
	}

	//--------------------------------------------------------------//
	//5. 按下之動作
	//--------------------------------------------------------------//

	public void actionPerformed(ActionEvent e) 
	{
	    String str = e.getActionCommand();
	    if (str.equals("建立連線")) //當按下建立連線後連線至本程式Server端(使用PrintStream與ServerSocket)
	    {
	    	try 
	    	{
	    		name = NameTextBox.getText(); //設定名字---此處為預設Server
		    	ip = IPTextBox.getText(); //設定IP---此處為預設本地IP
		    	EstablishConnection(); //建立連線----
		    	Thread readerThread = new Thread(new IncomingReader()); //new一個Tread放IncomingReader物件或可以說建立接收資料執行緒
		    	readerThread.start(); //開始連結物件
	    	}
	    	catch (Exception ex)
	    	{
	    		ex.printStackTrace();
	    	}
	    } 
	    else if (str.equals("送出")) //當按下送出後傳送訊息(使用PrintStream)
	    {
	    	if ((ip != null) && (sendTextBox.getText() != "") && (name != "")) //不可沒有ip、名字及送出空白
	    	{
	    		try 
	    		{ 
	    			String ServerIP = InetAddress.getLocalHost().getHostAddress();//scanning ServerIP address
	    			writer.println(( name + "(" + ServerIP + ")：\r\n" + sendTextBox.getText())); //送出資料
	    			writer.flush(); //刷新該串流的緩衝。
	    		} 
	    		catch (Exception ex) 
	    		{
	    			System.out.println("送出資料失敗");
	    			state.setText("送出資料失敗"); //偵錯用
	    		}
	    		sendTextBox.setText(""); //清完輸入欄位
	    	}
	    } 
	    else if (str.equals("SaveFile")) //當按下SaveFile選項後儲存聊天內容
	    {
	    	try 
	    	{
	    		FileWriter f = new FileWriter("history_Content_Server.txt"); //將聊天紀錄存入TXT檔
	    		f.write(incoming.getText()); //寫入
	    		f.close(); //關閉寫入
	    		state.setText("儲存檔案成功"); //左下角狀態顯示
	    	} 
	    	catch (IOException e2) 
	    	{
	    		state.setText("儲存檔案失敗"); //偵錯用
	    	}
	    }
	    else if (str.equals("選取圖片")) //當按下選取圖片按鈕後送出圖片
	    {
	    	try 
    		{ 
	    		String ServerIP = InetAddress.getLocalHost().getHostAddress();//scanning ServerIP address
	    		JFileChooser fileChooser = new JFileChooser();//宣告filechooser 
			    int returnValue = fileChooser.showOpenDialog(null);//叫出filechooser 
			    if (returnValue == JFileChooser.APPROVE_OPTION) //判斷是否選擇檔案 
			    { 
			    	File selectedFile = fileChooser.getSelectedFile();//指派給File 
			    	Icon img = new ImageIcon(selectedFile.getPath());
			    	writer.println(( name + "(" + ServerIP + ")：\r\n") + img ); //送出資料
			    	//下方為圖片實例化但與預期仍有落差
//			    	byte buffer[] = new byte[1024];
//			    	FileInputStream fis= new FileInputStream(new File(img.toString()));
//			    	fis.read(buffer);
//			    	writer.write(buffer, 0, 1024);
//	    			writer.flush(); //刷新該串流的緩衝。
			    } 
    		} 
    		catch (Exception ex) 
    		{
    			System.out.println("選取圖片失敗");
    			state.setText("選取圖片失敗"); //偵錯用
    		}
    		sendTextBox.setText(""); //清完輸入欄位
	    }
	    else if (str.equals("關閉聊天室系統")) //當按下關閉聊天室系統按鈕後關閉Server程式
	    {
	    	System.exit(0); //關閉檔案
	    }
	}
}
