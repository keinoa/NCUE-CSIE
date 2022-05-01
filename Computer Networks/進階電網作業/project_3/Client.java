import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;
import javax.swing.*; 
import java.util.Scanner;

//--------------------------------------------------------------//
//程式流程
//---Client   --主類別檔
//1. main()   --主程式進入點
//2. Client()   --   --設定及宣告
//3. EstablishConnection() --方法   --建立連線
//4. class IncomingReader --內部類別  --接收資料
//5. actionPerformed()  --方法   --按下之動作
//--------------------------------------------------------------//

//--------------------------------------------------------------//
//Client主類別檔
//--------------------------------------------------------------//

@SuppressWarnings("serial")
//直接在class內extends物件JFrame後便可直接寫入視窗程式
public class Client extends JFrame implements ActionListener 
{
	//宣告區
	//設定名子、IP以及PrintStream物件
	Scanner input = new Scanner(System.in);
	String name = "", ip = "";
	PrintStream writer;
	
	//建立Socket變數
	Socket sock;
	
	//顯示區域
	JTextArea incoming = new JTextArea(15, 50); //build TextArea row:15 column:50
	
	//輸入區域
	JLabel state = new JLabel("電腦網路進階"); //build label
	JLabel NameLabel = new JLabel("請輸入使用者名稱："); //build label
	JLabel IPLabel = new JLabel("輸入Server IP："); //build label
	JTextArea sendTextBox = new JTextArea(2, 35); //build TextArea row:2 column:35
	JTextField NameTextBox = new JTextField("", 10); //build TextBox
	JTextField IPTextBox = new JTextField("", 10); //build TextBox
	
	//menu
	MenuBar mBar = new MenuBar(); //創建下拉式選單
	//File
	Menu mFile = new Menu("File"); //檔案選單按鈕
	//SaveFile
	MenuItem mFileSave = new MenuItem("SaveFile"); //存檔案選單按鈕
  
	//--------------------------------------------------------------//
	//1. 主程式進入點
	//--------------------------------------------------------------//
  
	public static void main(String[] args) 
	{
		@SuppressWarnings("unused")
		Client client = new Client(); //宣告物件Client開始程式
	}

	//--------------------------------------------------------------//
	//2. 設定及宣告視窗物件
	//--------------------------------------------------------------//
	
	Client() 
	{
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~對話區域定位在上面~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
		super("Client端");//建立視窗JFrame
		JPanel Build = new JPanel();//用來放name及ip--設定區域
	    JButton setServerIP = new JButton("開始連線");//建來設定按鍵
	    setServerIP.addActionListener(this);//按下設定
	    
	    //名字
	    Build.add(NameLabel);
	    Build.add(NameTextBox);
	    
	    //IP address
	    Build.add(IPLabel);
	    Build.add(IPTextBox);
	    
	    //設定ServerIP
	    Build.add(setServerIP);
	    getContentPane().add(BorderLayout.NORTH, Build);
	    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~對話區域定位在上面~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
			    
	    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~對話區域定位在中間~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	    JButton sendButton = new JButton("送出"); //JButton("送出")
	    sendButton.addActionListener(this); //按下
	    
	    JButton leave = new JButton("離開聊天室"); //JButton("離開聊天室")
	    leave.addActionListener(this); //按下
	    
	    JButton selgraph = new JButton("選取圖片"); //JButton("選取圖片")
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
	    
	    setSize(600, 480); //JFrame視窗大小600x480
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

	private void EstablishConnection()  //建立連線
	{
	    try 
	    {
	    	sock = new Socket(ip, 10000); //NEW一個傳至server的socket
	    	
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
	    		while ((message = input.nextLine()) != null) //先做讀取input在判斷是否為空 
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
	    String str = e.getActionCommand(); //存取目前按下按鈕上的文字訊息
	    if (str.equals("開始連線")) //當按下開始連線後連線至本程式Server端(使用PrintStream與ServerSocket)
	    {
	    	try
	    	{
	    		name = NameTextBox.getText(); //設定名字
		    	ip = IPTextBox.getText(); //設定IP
		    	EstablishConnection(); //建立連線----
		    	Thread readerThread = new Thread(new IncomingReader()); //建立接收資料執行緒----
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
	    			String ClientIP = InetAddress.getLocalHost().getHostAddress(); //scanning ClientIP address
    				writer.println(( name + "(" + ClientIP + ")：\r\n" + sendTextBox.getText())); //送出資料
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
	    		FileWriter f = new FileWriter("history_Content_Client.txt"); //將聊天紀錄存入TXT檔
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
	    		String ClientIP = InetAddress.getLocalHost().getHostAddress();//scanning ClientIP address
	    		JFileChooser fileChooser = new JFileChooser();//宣告filechooser 
			    int returnValue = fileChooser.showOpenDialog(null);//叫出filechooser 
			    if (returnValue == JFileChooser.APPROVE_OPTION) //判斷是否選擇檔案 
			    { 
			    	File selectedFile = fileChooser.getSelectedFile();//指派給File 
			    	Icon img = new ImageIcon(selectedFile.getPath());
			    	writer.println(( name + "(" + ClientIP + ")：\r\n") + img ); //送出資料
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
	    else if (str.equals("離開聊天室")) //當按下離開聊天室按鈕後關閉Client程式
	    {
	    	System.exit(0); //關閉檔案
	    }
	}
}