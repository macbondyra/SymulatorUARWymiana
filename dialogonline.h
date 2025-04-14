#ifndef DIALOGONLINE_H
#define DIALOGONLINE_H

#include <QDialog>


namespace Ui {
class DialogOnline;
}

class DialogOnline : public QDialog
{
    Q_OBJECT

public:
    explicit DialogOnline(QWidget *parent = nullptr);
    ~DialogOnline();

private:
    Ui::DialogOnline *ui;
    QString getIp();
    quint16 getPort();
    enum class trybPracy{Regulator,Obiekt};
    trybPracy getTryb();


};

#endif // DIALOGONLINE_H
