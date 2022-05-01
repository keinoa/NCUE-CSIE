import java.net.*;
import java.util.*;
import java.io.*;

/**
 * Created by 陳柏維 on 2021/05/09.
 *
 *
 */

public class Server {
	public static void main(String args[])throws Exception
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		//#主要宣告
		Scanner input = new Scanner(System.in);//class宣告
		DatagramPacket packet;//class宣告
		DatagramSocket socket;//class宣告
		String ServerIP = InetAddress.getLocalHost().getHostAddress();//scanning ServerIP address
		String name;	//玩家名稱
		String time;	//遊玩時間(ms/1000)
		String cnt;		//計遊玩次數
		String sel;		//是否繼續遊玩
		byte[] buffer;	//容器
		int portNo;		//port
		String Name[] = new String[1024]; //存TXT檔內所有玩家名稱
		int play_time[] = new int[1024];  //存TXT檔內所有遊玩時間
		int play_cnt[] = new int[1024];	  //存TXT檔內所有遊玩次數
		int rank_que ;					  //排名用
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		//#輸入欲使用之port
		System.out.print("Server " + ServerIP + " >> 請輸入port：");
		portNo =  input.nextInt() + 1;//傳送用port
		socket = new DatagramSocket(portNo-1);//build socket, 並設定接收用port
		//注意:傳送與接收必須不同port不然會報錯(p.s.此處是對應Server與Client使用的傳送與接收)
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		
		while(true)
		{
			
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			//#設定題目
			System.out.println("(N個字元的字串, 字元不重複."
					+ "輸入0結束程式。可用字元為："
					+ "{0, 1, 2, 3, 4, 5, 6, 7, 8, 9"
					+ ", A, B, C, D, E, F})");//題目範圍條件
			System.out.print("請輸入位數N：");
			String N = input.next();//抓N位數
			int convert_N =  Integer.parseInt(N);//轉integer type
			if( convert_N == 0 )break;//若為0直接跳結束
			
			System.out.print(N+"位數的正確字串：");
			String ans = input.next();//存下答案，以便後續比對
			char rig_ = ans.charAt(0);
			if( ans.length() == 1 && rig_ == '0' ) break;
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			//接收Client端IP
			buffer = new byte[16];//new一個新空間
			packet = new DatagramPacket(buffer,buffer.length);//給他16byte的空間存取
			socket.receive(packet);//接收
			String ClientIP = new String(buffer, 0, packet.getLength());//接收ClientIP
			InetAddress Clientaddr = InetAddress.getByName(ClientIP);//get IP address of Client
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			//傳送題目長度給Client端
			String msg = N;//欲送出之資訊(題目字串長度)
			buffer = new byte[msg.length()];//new一個新空間長度為欲送訊息的長度
			buffer = msg.getBytes();//賦予buffer該字串的byte值
			packet = new DatagramPacket(buffer, msg.length(), Clientaddr, portNo );//包裝訊息
			socket.send(packet);//送出
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			
			while(true)
			{
				
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				//接收Client端所猜測之答案
				buffer = new byte[1024];//new一個新空間
				packet = new DatagramPacket(buffer,buffer.length);//給他1024byte的空間存取
				socket.receive(packet);//接收
				msg = new String(buffer, 0, packet.getLength());//Client猜測之答案
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				//與題目做比較判斷幾A幾B
				int A = 0, B = 0;
				for( int i = 0 ; i < msg.length(); i++ )
				{
					for( int j = 0 ; j < msg.length(); j++ )
					{
						if(msg.charAt(i) == ans.charAt(j) && i == j) //判斷是否同位置同字元，是：紀錄A後跳出
						{
							A++;
							break;
						}
						else if(msg.charAt(i) == ans.charAt(j)) B++; //判斷是否不同位置同字元
					}
				}
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				//將幾A幾B拼成字串後傳出
				String send_msg = A + "A" + B + "B";
				buffer = new byte[send_msg.length()];//new一個新空間長度為欲送訊息的長度s
				buffer = send_msg.getBytes();//賦予buffer該字串的byte值
				packet = new DatagramPacket(buffer, send_msg.length(), Clientaddr, portNo);//將訊息包裝好
				socket.send(packet);//傳出
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				//將幾A幾B拼成字串後傳出
				String A_cnt = A + "" ;
				buffer = new byte[A_cnt.length()];//new一個新空間長度為欲送訊息的長度s
				buffer = A_cnt.getBytes();//賦予buffer該字串的byte值
				packet = new DatagramPacket(buffer, A_cnt.length(), Clientaddr, portNo);//將訊息包裝好
				socket.send(packet);//傳出
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				
				//若A的數量與題目字串長度相等便跳出迴圈(P.S. 全對)
				if( A == convert_N ) break;
			}
			
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			//接收玩家名稱
			buffer = new byte[1024];//new一個新空間
			packet = new DatagramPacket(buffer,buffer.length);//給他1024byte的空間存取
			socket.receive(packet);//接收
			name = new String(buffer, 0, packet.getLength());//name存玩家名
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			//接收遊玩次數
			buffer = new byte[1024];//new一個新空間
			packet = new DatagramPacket(buffer,buffer.length);//給他1024byte的空間存取
			socket.receive(packet);//接收
			cnt = new String(buffer, 0, packet.getLength());//cnt存遊玩次數
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			//接收遊玩時間
			buffer = new byte[1024];//new一個新空間
			packet = new DatagramPacket(buffer,buffer.length);//給他1024byte的空間存取
			socket.receive(packet);//接收
			time = new String(buffer, 0, packet.getLength());//Client猜測之答案
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			
			try 
			{
				FileWriter fw = new FileWriter("rank.txt", true);//class宣告
	            fw.write( name + "\r\n" + cnt + "\r\n" + time + "\r\n" + "?\r\n" );//在最後面多塞?以便判斷
	            fw.flush();
	            fw.close();//關閉寫入
	        } 
			catch (Exception e) {
	            System.out.println("Something Error");//出錯時直接跳這
	        }
			
			rank_que = 0;//初始化排名
			try 
			{
	            Scanner fr = new Scanner(new File("rank.txt"));//class宣告
	            
	            int a = 0;//紀錄總共幾組資料
	            while (true)
	            {
	            	Name[a] = fr.nextLine();//存TXT檔內的玩家名稱
	            	char rig = Name[a].charAt(0); 
	            	if( rig == '?' )//判斷是不是最後
	            	{
	            		Name[a] = "";//清掉?
	            		break; 
	            	}
	            	play_cnt[a] = Integer.parseInt(fr.nextLine());//存TXT檔內的遊玩次數
	            	play_time[a] = Integer.parseInt(fr.nextLine());//存TXT檔內的遊玩時間
	            	a++;
	            }
	            
	            //除錯用
//	            for(int i = 0; i <= a ; i++)
//	            {
//            		System.out.println(Name[i] + ", " + play_cnt[i] + ", " + play_time[i]);
//	            }
	            
	            if( a != 1 )//用bubble sort排排名由小到大先排遊玩次數再來遊玩時間
	            {
	            	for(int i = a-1; i > 0; i--)
		            {
		                for(int j = 0; j <= i-1; j++)
		                {
		                	int rig1 = play_time[j];//在寫得時候發現Java常有一些bug故另外存值
		                	int rig2 = play_time[j+1];
		                    if( rig1 > rig2 )
		                    {
		                    	String rig = Name[j];//swap
		                    	Name[j] = Name[j+1];
		                    	Name[j+1] = rig;
		                    	
		                    	int rige = play_cnt[j];//swap
		                    	play_cnt[j] = play_cnt[j+1];
		                    	play_cnt[j+1] = rige;
		                    	
		                    	rige = play_time[j];//swap
		                    	play_time[j] = play_time[j+1];
		                    	play_time[j+1] = rige;
		                    }
		                    else if( rig1 == rig2 )//在寫得時候發現Java常有一些bug故另外存值
			            	{
		                    	rig1 = play_cnt[j];
			                	rig2 = play_cnt[j+1];
			            		if( rig1 > rig2 )
		            			{
			            			String rig = Name[j];//swap
			                    	Name[j] = Name[j+1];
			                    	Name[j+1] = rig;
			                    	
			                    	int rige = play_cnt[j];//swap
			                    	play_cnt[j] = play_cnt[j+1];
			                    	play_cnt[j+1] = rige;
			                    	
			                    	rige = play_time[j];//swap
			                    	play_time[j] = play_time[j+1];
			                    	play_time[j+1] = rige;
		            			}
			            	}
		                }
		            }
	            }
	            
	            while(true) 
	            {
	            	boolean contain = true;//預設為true(在TXT檔找到)
	            	int Time = Integer.parseInt(time);//把本次猜測時間轉int type
	            	int Cnt = Integer.parseInt(cnt);//把本次猜測次數轉int type
	            	if( Name[rank_que].length() == name.length())//找名字長度與本次測試玩家名稱相同的
	            	{
	            		int cmp = name.length();//name長度
	            		for( int i = 0; i < cmp ; i++ )//判斷字元是否相同用loop
	            		{
	            			if(Name[rank_que].charAt(i) != name.charAt(i))//判斷
	            				contain = false;
	            		}
	            		if( play_time[rank_que] != Time || play_cnt[rank_que] != Cnt )//判斷時間與次數是否一致
	            			contain = false;
	            	}
	            	else contain = false;
	            	if( contain == true )//找到完全相同
	            		break;
	            	rank_que++;//每次都從第一名開始找依序往下
	            }
	            rank_que++;//重0開始故正式排名要+1
	            
	            // Constructs a FileWriter object given a file name.
	            FileWriter fw = new FileWriter("rank.txt");//class宣告
	            for(int i = 0 ; i < a; i++)
	            {
	            	String rig1 = Name[i] + "\r\n" ;
	            	String rig2 = play_cnt[i] + "\r\n" ;
	            	String rig3 = play_time[i] + "\r\n" ;
	            	fw.write( rig1 + rig2 + rig3 );//把?去掉並排好後依序存入
	            }
	            FileWriter fhtml = new FileWriter("rank.html");//class宣告
	            fhtml.write( "<!DOCTYPE html>"
	            		+ "<html lang='en'>"
	            		+ "<head>"
	            		+ "<meta charset='UTF-8'>"
	            		+ "<meta http-equiv='X-UA-Compatible' content='IE=edge'>"
	            		+ "<meta name='viewport' content='width=device-width, initial-scale=1.0'>"
	            		+ "<title>Document</title>"
	            		+ "</head><body>");//寫入html
	            
	            for(int i = 0 ; i < a; i++)
	            {
	            	if( i+1 == rank_que )
	            	{
	            		fhtml.write( "<h4><div>" + "玩家名稱：" + Name[i] 
	            				+ "&nbsp&nbsp" + "遊玩次數：" + play_cnt[i] 
	            						+ "次&nbsp&nbsp" + "遊玩時間：" 
	            				+ play_time[i] + "&nbsps&nbsp" + "</div></h4>" );//寫入html
	            		continue;
	            	}
	            	fhtml.write( "<div>" + "玩家名稱：" + Name[i] + "&nbsp&nbsp" 
	            	+ "遊玩次數：" + play_cnt[i] + "次&nbsp&nbsp" + "遊玩時間：" 
	            			+ play_time[i] + "&nbsps&nbsp" + "</div>" );//寫入html
	            	
	            }
	            fhtml.write("</body></html>");
	            fw.flush();//強制發出緩衝data
	            fr.close();//關閉讀取
	            fw.close();//關閉寫入
	            fhtml.close();//關閉HTML寫入
	        } 
			catch (Exception e) 
			{
	            System.out.println("Something Error");
	        }
			
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			//傳送排名給Client
			String Rank = rank_que + "";
			buffer = new byte[Rank.length()];//new一個新空間長度為該字串長
			buffer = Rank.getBytes();//賦予buffer該字串的byte值
			packet = new DatagramPacket(buffer, Rank.length(), Clientaddr, portNo);//將訊息包裝好
			socket.send(packet);//傳出
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
						
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			//接收是否繼續遊玩
			buffer = new byte[1024];//new一個新空間
			packet = new DatagramPacket(buffer,buffer.length);//給他1024byte的空間存取
			socket.receive(packet);//接收
			sel = new String(buffer, 0, packet.getLength());//Client猜測之答案
			char transfer = sel.charAt(0);//將String轉char(測試時發現不轉讀不出指定字元)
			if( transfer == '1' ) //若為1繼續玩，否則就跳出不玩
			{
				System.out.println("---------------------------分隔線---------------------------");
				continue;
			}
			else 
				break;
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		}
		System.out.println("---------------------------End---------------------------");
  	  	socket.close();//關閉socket
  	  	input.close();//關閉input
	}

}
