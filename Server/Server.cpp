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
			
		        printf("�H���u�i�R\n");
				 printf("�H���u�i�R\n");
				  printf("�H���u�i�R\n");
				   printf("�H���u�i�R\n");
				    printf("�H���u�i�R\n");
					 printf("�H���u�i�R\n");
					  printf("�H���u�i�R\n");
					   printf("�H���u�i�R\n");
					    printf("�H���u�i�R\n");
						 printf("�H���u�i�R\n");
						  printf("����\n");
			
			
		}
		
		if(strcmp(buff,"keyboard")==0)
		{

		}

		if(strcmp(buff,"rebot")==0)
		{
			
			if(ExitWindowsEx(EWX_LOGOFF,0))
			{
				printf("���s�}��");
				return 0;
			}
		}

		// ������u,���s���ݳs�u		
		if(strcmp(buff,"leave")==0)
		{
			
			printf("������u");
			::closesocket(sServer);
			InitSocket();
		}
	}



	// �����P�Τ�ݪ��s��
	::closesocket(sServer);
		
	return 0;


}

int InitSocket()
{

	// �إ߮M�`�r
	SOCKET sListen = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(sListen == INVALID_SOCKET)
	{
		printf("Failed socket() \n");
		return 0;
	}
	
	// ��Rsockaddr_in���c
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(8888);
	sin.sin_addr.S_un.S_addr = INADDR_ANY;
	
	// �j�w�o�ӮM�`�r��@�ӥ��a��}
	if(::bind(sListen, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		printf("Failed bind() \n");
		return 0;
	}
	
	// �i�J��ť�Ҧ�
	if(::listen(sListen, 2) == SOCKET_ERROR)
	{
		printf("Failed listen() \n");
		return 0;
	}
	
	sockaddr_in remoteAddr; 
	int nAddrLen = sizeof(remoteAddr);

	// �����@�ӷs�s��
	sServer = ::accept(sListen, (SOCKADDR*)&remoteAddr, &nAddrLen);

	if(sServer == INVALID_SOCKET)
	{
		printf("Failed accept()");
	}
		
	printf(" ������@�ӳs���G%s \r\n", inet_ntoa(remoteAddr.sin_addr));


	// ������ť�M�`�r
	::closesocket(sListen);

	return 1;
}
