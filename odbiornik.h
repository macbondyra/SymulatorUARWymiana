#ifndef ODBIORNIK_H
#define ODBIORNIK_H

#include <QObject>
#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>
class ARXModel;
class Odbiornik : public QObject
{
    Q_OBJECT
public:
    explicit Odbiornik(QObject *parent = nullptr, ARXModel* model = nullptr);
    void setIp(QString ipnew);
    void setPort(quint16 portnew);
    void startListening();
private:
    QTcpServer server;
    QString ip;
    quint16 port;
    bool connectionState;
    ARXModel* modelARX;
    QTcpSocket* clientSocket;

signals:

private slots:
    void newClient();
    void readData();
    //void connectionStarted();
   // void onClientDisconnected();


};

#endif // ODBIORNIK_H
