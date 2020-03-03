#ifndef CLIENTSERVER_H
#define CLIENTSERVER_H
#include <winsock2.h>
#include <game.h>

class clientServer
{

public:
    clientServer();
    ~clientServer();
    bool initServer();
    bool initClient();
    void sendMove(const sMove);
    void receiveMove(sMove &);

private:
    WSADATA wsaData;
    SOCKET mainSocket;
    sockaddr_in service;
    bool checkFlag;



};

#endif // CLIENTSERVER_H
