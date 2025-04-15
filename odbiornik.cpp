#include "odbiornik.h"
#include <QMessageBox>

Odbiornik::Odbiornik(QObject *parent,ARXModel* model)
    : QObject{parent}
    ,modelARX(model)
{
    connectionState=false;
    connect(&server,SIGNAL(newConnection()),this,SLOT(newClient()));
}

void Odbiornik::setIp(QString ipnew)
{
    ip = ipnew;
}

void Odbiornik::setPort(quint16 portnew)
{
    port = portnew;
}

void Odbiornik::startListening()
{
    QHostAddress address;
    address.setAddress(ip);
    if(!server.isListening()){
        if (server.listen(address, port)) {
            QMessageBox::information(nullptr, "Status", "Uruchomiono serwer");
            connectionState=true;
        } else {
            QMessageBox::critical(nullptr, "Błąd", "Nie udało się uruchomić serwera:\n" + server.errorString());
        }
    }
}

void Odbiornik::newClient()
{
    clientSocket = server.nextPendingConnection();
    if (clientSocket) {
        connect(clientSocket, &QTcpSocket::readyRead, this, &Odbiornik::readData);
        connect(clientSocket, &QTcpSocket::disconnected, clientSocket, &QTcpSocket::deleteLater);
        QMessageBox::information(nullptr, "Status", "Nowy klient połączony.");
    }
}
void Odbiornik::readData()
{
    if (!clientSocket) return;

    QByteArray receivedData = clientSocket->readAll();
    QString dataStr = QString::fromUtf8(receivedData);
    qDebug() << "Otrzymano dane: " << dataStr;


    QMessageBox::information(nullptr, "Odebrana wiadomość", "Serwer odebrał: " + dataStr);


    QString responseMsg = "Wiadomość z serwera: Odebrano Twoją wiadomość!";
    clientSocket->write(responseMsg.toUtf8());
}
