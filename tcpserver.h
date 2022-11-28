#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QThread>
#include <QHostAddress>
#include <QDebug>
#include <QTcpSocket>

class TcpServer : public QThread
{
    Q_OBJECT

public Q_SLOT:
    void newConnection();
    void newData();

public:
    TcpServer();
    void run() override;
    void setup();
private:
    QTcpServer *tcpServer;
};

#endif // TCPSERVER_H
