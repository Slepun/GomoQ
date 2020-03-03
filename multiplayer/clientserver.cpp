#include "clientserver.h"
#include <iostream>
using namespace std;

clientServer::clientServer()
{
    checkFlag = true;
    int result = WSAStartup( MAKEWORD( 2, 2 ), & wsaData );
    if( result == NO_ERROR )
    {
        mainSocket = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
    }
    else
    {
        checkFlag = false;
        cout << "Initialization error" << endl;
    }


    if( mainSocket != INVALID_SOCKET )
    {
        memset( & service, 0, sizeof( service ) );
        service.sin_family = AF_INET;
        service.sin_addr.s_addr = inet_addr( "127.0.0.1" );
        service.sin_port = htons( 27015 );
    }
    else
    {
        checkFlag = false;
        cout << "Error creating socket: " << WSAGetLastError() << endl;
        WSACleanup();
    }


}

clientServer::~clientServer()
{
    closesocket(mainSocket);
    WSACleanup();
    checkFlag = true;
}

bool clientServer::initServer()
{
    if( checkFlag == true &&
        bind(mainSocket, reinterpret_cast<SOCKADDR*>(&service), sizeof( service )) == SOCKET_ERROR )
    {

        cout << "bind() failed" << endl;
        closesocket( mainSocket );
        checkFlag = false;
    }

    if( checkFlag && listen( mainSocket, 1 ) == SOCKET_ERROR )
    {
        checkFlag = false;
        printf( "Error listening on socket.\n" );
    }

    if( checkFlag )
    {
        SOCKET acceptSocket = SOCKET_ERROR;
        cout << "Waiting for a client to connect..." << endl;

        while( acceptSocket == SOCKET_ERROR )
        {
            acceptSocket = accept( mainSocket, NULL, NULL );
        }

        cout << "Client connected" << endl;
        mainSocket = acceptSocket;
    }
    return checkFlag;
}

bool clientServer::initClient()
{
    if( checkFlag &&
        connect(mainSocket, reinterpret_cast<SOCKADDR*>(&service), sizeof(service)) == SOCKET_ERROR )
    {
        checkFlag = false;
        cout << "Failed to connect." << endl;
        WSACleanup();
    }
    return checkFlag;
}

void clientServer::sendMove(const sMove move)
{
    char sendMove[3] = "";
    sendMove[0] = move.row;
    sendMove[1] = move.col;
    send( mainSocket, sendMove, strlen(sendMove), 0 );
    cout << "Data send" << endl;
}

void clientServer::receiveMove(sMove &moveOut)
{
    int bytesRecv = SOCKET_ERROR;
    char recMove[3] = "  ";

    while( bytesRecv == SOCKET_ERROR )
    {
        bytesRecv = recv( mainSocket, recMove, strlen(recMove), 0 );
        if( bytesRecv == 0 || bytesRecv == WSAECONNRESET )
            {
                printf( "Connection closed.\n" );
                break;
            }

            if( bytesRecv < 0 )
                 return;
    }
    cout << "Received data " << recMove << endl;
    moveOut.row = recMove[0];
    moveOut.col = recMove[1];

}

