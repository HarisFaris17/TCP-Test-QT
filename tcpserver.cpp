#include "tcpserver.h"

TcpServer::TcpServer():
    tcpServer(new QTcpServer)
{
    setPriority(HighPriority);
}

void TcpServer::run(){
    while(tcpServer->hasPendingConnections()){
        QTcpSocket *tcpClient = tcpServer->nextPendingConnection();
        connect(tcpClient,&QTcpSocket::readyRead,this,&TcpServer::newData);
        qDebug()<<"local address "<<tcpClient->localAddress();
        qDebug()<<"peer address "<<tcpClient->peerAddress();

//        if(tcpServer)
    }
}

void TcpServer::setup(){
    connect(tcpServer,&QTcpServer::newConnection,this,&TcpServer::run);
    tcpServer->listen(QHostAddress::Any,666);
    qDebug()<<"IP : "<<tcpServer->serverAddress().toString()<<"\nPort : "<<tcpServer->serverPort();
}

void TcpServer::newConnection(){
    qDebug()<<tcpServer->hasPendingConnections();
    start(HighPriority);
}

void TcpServer::newData(){
    QTcpSocket *tcpClient = qobject_cast<QTcpSocket*> (sender());
    qDebug()<<tcpClient->readAll();
}


