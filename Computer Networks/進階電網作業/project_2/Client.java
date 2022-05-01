import java.net.*;
import java.util.*;

/**
 * Created by 陳柏維 on 2021/05/09.
 *
 *
 */

public class Client {
	
	public static void main(String args[])throws Exception
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		//#主要宣告
		Scanner input = new Scanner(System.in);//new一個class使用
		DatagramPacket packet;//class宣告
		DatagramSocket socket;//class宣告
		String ClientIP = InetAddress.getLocalHost().getHostAddress();//scanning ClientIP address
		char sel; 		//選擇是否繼續玩
		byte[] buffer;	//容器
		int portNo;		//port
		int cnt = 0;	//計遊玩次數
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		//#輸入名字
		System.out.print("Client " + ClientIP + " >> 請輸入你的名字：");
		String name = input.next();
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		//#輸入欲連線之IP address
		System.out.print("Client " + ClientIP + " >> 請輸入Server IP：");
		String ServerIP = input.next();	//scanning ServerIP	address
		InetAddress Serveraddr = InetAddress.getByName(ServerIP); //get IP address of Server
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		//#輸入欲使用之port
		System.out.print("Client " + ClientIP + " >> 請輸入port：");
		portNo =  input.nextInt();//傳送用port
		socket = new DatagramSocket(portNo+1);//build socket, 並設定接收用port
		//注意:傳送與接收必須不同port不然會報錯(p.s.此處是對應Server與Client使用的傳送與接收)
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		
		while(true)
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			//#送出ClientIP給Server
			buffer = new byte[ClientIP.length()];//new一個新空間長度為欲送訊息的長度
			buffer = ClientIP.getBytes();//賦予buffer該字串的byte值
			packet = new DatagramPacket(buffer, ClientIP.length(), Serveraddr, portNo);//包裝訊息
			socket.send(packet);//傳出
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			//#等待接收數字的個數(N個數字/文字)
			System.out.println("Loading...");
			buffer = new byte[1024];//new一個新空間
			packet = new DatagramPacket(buffer,buffer.length);//給他1024byte的空間存取
			socket.receive(packet);//取得Server所送之資訊
			String N = new String(buffer, 0, packet.getLength());//將該資訊存於此
			System.out.println("要猜的字串是" + N + "個字元，可用字元為：{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F}");
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			
			//#開始計時(ms)
			long start_time = System.currentTimeMillis();//取得系統時間開始計時
			
			while(true)
			{
				cnt++;
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				//Step B&C 將猜測答案送給Server端
				System.out.print("請輸入你猜的字串：");
				String myans = input.next();
				buffer = new byte[myans.length()];//new一個新空間長度為欲送訊息的長度
				buffer = myans.getBytes();//賦予buffer該字串的byte值
				packet = new DatagramPacket(buffer, myans.length(), Serveraddr, portNo);//包裝資訊到packet
				socket.send(packet);//送出packet
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				//接收比對結果
				buffer = new byte[1024];//new一個新空間
				packet = new DatagramPacket(buffer,buffer.length);//給他1024byte的空間存取
				socket.receive(packet);//取得Server所送之資訊
				String ans = new String(buffer, 0, packet.getLength());//將該資訊存於此
				System.out.println("比對結果：" + ans);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				//接收比對結果
				buffer = new byte[1024];//new一個新空間
				packet = new DatagramPacket(buffer,buffer.length);//給他1024byte的空間存取
				socket.receive(packet);//取得Server所送之資訊
				String A_cnt = new String(buffer, 0, packet.getLength());//將該資訊存於此
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				
				//若A的數量與題目字串長相等便跳出迴圈
				if( Integer.parseInt(A_cnt) == Integer.parseInt(N) ) break;
			}
			
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			//#結算遊玩時間與次數
			long end_time = System.currentTimeMillis();//取得目前計數(ms)
			long total_time = (end_time-start_time)/1000;//計秒|開始-結束|/1000
			System.out.println("共猜了" + cnt + "次" + ", 花費: " + total_time + "sec");
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			//#將玩家姓名寄給Server
			buffer = new byte[name.length()];//new一個新空間長度為欲送訊息的長度
			buffer = name.getBytes();//賦予buffer該字串的byte值
			packet = new DatagramPacket(buffer, name.length(), Serveraddr, portNo);//包裝資訊進packet裡
			socket.send(packet);//送出packet給Server
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			//#將遊玩次數寄給Server
			buffer = new byte[1024];//new一個新空間
			buffer = (""+cnt).getBytes();//賦予buffer該字串的byte值
			packet = new DatagramPacket(buffer, (""+cnt).length(), Serveraddr, portNo);//包裝資訊進packet裡
			socket.send(packet);//送出packet給Server
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			//#將遊玩時間寄給Server
			buffer = new byte[1024];//new一個新空間
			buffer = (""+total_time).getBytes();//賦予buffer該字串的byte值
			packet = new DatagramPacket(buffer, (""+total_time).length(), Serveraddr, portNo);//包裝資訊進packet裡
			socket.send(packet);//送出packet給Server
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			//#接收Server端傳送之排名
			buffer = new byte[1024];//new一個新空間
			packet = new DatagramPacket(buffer, buffer.length);//給他1024byte的空間存取
			socket.receive(packet);//接受自Server的資訊
			String rank = new String(buffer, 0, packet.getLength());//將資訊存於此
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			
			System.out.print("Client " + ClientIP + " >> " + name + ",恭喜你答對了! 你的排名:" + rank + "\r\n");
			
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			//#判斷是否為指定輸出,確保送出的是0/1
			while(true) {
	  	  	  	System.out.print("是否要再玩一次( 0:No or 1:Yes )? 請輸入0/1: ");
	  	  	  	sel = input.next().charAt(0);//抓選項,由於用String會偵測不到故使用char
	  	  	  	if ( sel == '0' || sel=='1' )
	  	  	  		break;//是0或1跳出while
	  	  	  	else
	  	  	  		System.out.println("輸入錯誤");//不是0或1繼續跑while
  	  	  	}
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			//寄送是否要在玩一次給server
	  			buffer = new byte[2];//new一個新空間
	  			buffer = (""+sel).getBytes();//將訊息放入buffer
	  			packet = new DatagramPacket(buffer, (""+sel).length(), Serveraddr, portNo);//包裝資訊於packet
	  	  	  	socket.send(packet);//將packet寄給server
	  	  	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	  	  	  	
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
  	  	  	if ( sel == '1' ) //繼續玩
  	  	  	{
  	  	  		cnt=0;//遊玩次數歸零
  	  	  		System.out.println("---------------------------分隔線---------------------------");
				continue;//重跑迴圈
			}
  	  	  	else if ( sel == '0' ) //結束
  	  	  		break;//跳出迴圈
  	  	  	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		}
		System.out.println("---------------------------End---------------------------");
  	  	socket.close();//關閉socket
  	  	input.close();//關閉input
	}
}
