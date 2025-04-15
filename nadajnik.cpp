#include "nadajnik.h"

#include <QMessageBox>

Nadajnik::Nadajnik(QObject *parent,PIDController* controller)
    : QObject{parent}
    , kontroler(controller)
{
    connectionState = false;
    ip="";
    port=0;
    connect(&socket,SIGNAL(readyRead()),this,SLOT(socketReadyRead()));
    connect(&socket, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(&socket, SIGNAL(errorOccurred(QAbstractSocket::SocketError)), this, SLOT(onConnectionError(QAbstractSocket::SocketError)));
}

void Nadajnik::setIP(QString ipnew)
{
    ip = ipnew;
}

void Nadajnik::setPort(quint16 portnew)
{
    port = portnew;
}

void Nadajnik::sendData(const QString &data)
{
    if (connectionState && socket.state() == QAbstractSocket::ConnectedState) {
        QByteArray byteData = data.toUtf8();
        socket.write(byteData);
    } else {
        QMessageBox::warning(nullptr, "Ostrzeżenie", "Brak połączenia z serwerem!");
    }
}

void Nadajnik::connectToHost()
{
    socket.connectToHost(this->ip,this->port);
}

void Nadajnik::disconnect()
{
    socket.disconnectFromHost();
    connectionState = false;
}

void Nadajnik::socketReadyRead()
{
    QByteArray response = socket.readAll();
    QString responseStr = QString::fromUtf8(response);
    qDebug() << "Odpowiedź serwera: " << responseStr;

    QMessageBox::information(nullptr, "Odebrana wiadomość", "Klient odebrał: " + responseStr);
}
void Nadajnik::onConnected()
{
    QMessageBox::information(nullptr,"Status","Połączono pomyślnie z hostem!");
    connectionState = true;
    sendData("Wiadomość z klienta: Cześć, serwerze!");
}

void Nadajnik::onConnectionError(QAbstractSocket::SocketError socketError)
{
    QMessageBox::information(nullptr,"Status","Błąd połączenia:"+socket.errorString());
    connectionState = false;
}
