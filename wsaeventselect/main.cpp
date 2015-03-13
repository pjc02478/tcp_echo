#include "stdafx.h"

#include <Windows.h>
#include <WinSock2.h>

#define MAX_CLIENTS 1024
#define MAX_SOCKETS (MAX_CLIENTS+1)

int _tmain(int argc, _TCHAR* argv[]){
	WSADATA w;
	SOCKET sock;
	HANDLE event;
	WSAEVENT event[MAX_SOCKETS];

	WSAStartup(0x0202, &w);

	SOCKADDR_IN addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9916);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET){
		closesocket(sock);
        return false;
    }
	if (bind(sock, (LPSOCKADDR)&addr, sizeof(addr)) == SOCKET_ERROR){
		 closesocket(sock);
        return false;
    }
    if (listen(sock, SOMAXCONN)){
		return false;
	}

	event = WSACreateEvent();

	if(WSAEventSelect(sock, event, FD_ACCEPT | FD_READ)){
	}

	
	while(true){
		auto retval = 
			WSAWaitForMultipleEvents(MAX_SOCKETS, &event, FALSE, WSA_INFINITE, FALSE);

		if(retval == WSA_WAIT_FAILED)
			return false;

		auto idx = retval - WSA_WAIT_EVENT_0;

		printf("%d\n", idx);
	}

	return 0;
}

