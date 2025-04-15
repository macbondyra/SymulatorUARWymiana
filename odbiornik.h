#ifndef ODBIORNIK_H
#define ODBIORNIK_H

#include <QObject>

class Odbiornik : public QObject
{
    Q_OBJECT
public:
    explicit Odbiornik(QObject *parent = nullptr);

signals:
};

#endif // ODBIORNIK_H
