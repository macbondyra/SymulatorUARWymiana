#ifndef NADAJNIK_H
#define NADAJNIK_H

#include <QObject>
#include <QtNetwork>
class Nadajnik : public QObject
{
    Q_OBJECT
public:
    explicit Nadajnik(QObject *parent = nullptr);

private:
    QTcpSocket socket;
    QString getIp();
    quint16 getPort();
signals:
};

#endif // NADAJNIK_H
