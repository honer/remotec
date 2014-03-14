// Server.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
int InitSocket();
SOCKET sServer;
CInitSock initSock;	


int main(int argc, char* argv[])
{
	InitSocket();
	char buff[256];

	while(1){

		int nRecv = ::recv(sServer,buff,256,0);
		
		if(nRecv>0)
		{
			buff[nRecv] = '\0';
			printf("%s\n",buff);
		
		}
		
		if(strcmp(buff,"cc")==0)
		{
			
		        printf("嘻哈真可愛\n");
				 printf("嘻哈真可愛\n");
				  printf("嘻哈真可愛\n");
				   printf("嘻哈真可愛\n");
				    printf("嘻哈真可愛\n");
					 printf("嘻哈真可愛\n");
					  printf("嘻哈真可愛\n");
					   printf("嘻哈真可愛\n");
					    printf("嘻哈真可愛\n");
						 printf("嘻哈真可愛\n");
						  printf("哈哈\n");
			
			
		}
		
		if(strcmp(buff,"keyboard")==0)
		{

		}

		if(strcmp(buff,"rebot")==0)
		{
			
			if(ExitWindowsEx(EWX_LOGOFF,0))
			{
				printf("重新開機");
				return 0;
			}
		}

		// 對方離線,重新等待連線		
		if(strcmp(buff,"leave")==0)
		{
			
			printf("對方離線");
			::closesocket(sServer);
			InitSocket();
		}
	}



	// 關閉同用戶端的連接
	::closesocket(sServer);
		
	return 0;


}

int InitSocket()
{

	// 建立套節字
	SOCKET sListen = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(sListen == INVALID_SOCKET)
	{
		printf("Failed socket() \n");
		return 0;
	}
	
	// 填充sockaddr_in結構
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(8888);
	sin.sin_addr.S_un.S_addr = INADDR_ANY;
	
	// 綁定這個套節字到一個本地位址
	if(::bind(sListen, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		printf("Failed bind() \n");
		return 0;
	}
	
	// 進入監聽模式
	if(::listen(sListen, 2) == SOCKET_ERROR)
	{
		printf("Failed listen() \n");
		return 0;
	}
	
	sockaddr_in remoteAddr; 
	int nAddrLen = sizeof(remoteAddr);

	// 接受一個新連接
	sServer = ::accept(sListen, (SOCKADDR*)&remoteAddr, &nAddrLen);

	if(sServer == INVALID_SOCKET)
	{
		printf("Failed accept()");
	}
		
	printf(" 接受到一個連接：%s \r\n", inet_ntoa(remoteAddr.sin_addr));


	// 關閉監聽套節字
	::closesocket(sListen);

	return 1;
}
