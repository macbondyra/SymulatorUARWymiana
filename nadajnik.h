#ifndef NADAJNIK_H
#define NADAJNIK_H

#include <QObject>
#include <QtNetwork>
class PIDController;
class Nadajnik : public QObject
{
    Q_OBJECT
public:
    explicit Nadajnik(QObject *parent = nullptr,PIDController* controller=nullptr);
    void setIP(QString ipnew);
    void setPort(quint16 portnew);
    void connectToHost();
    void sendData(const QString &data);
private:
    PIDController* kontroler;
    QTcpSocket socket;
    QString getIp();
    quint16 getPort();
    QString ip;
    quint16 port;
    bool connectionState;

    void disconnect();
signals:

private slots:
    void socketReadyRead();
    void onConnected();
    void onConnectionError(QAbstractSocket::SocketError socketError);
};

#endif // NADAJNIK_H
