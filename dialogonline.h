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
    QString getIp();
    quint16 getPort();
    int getTryb();
    bool getCzyTrybJednostronny();
private slots:
    void on_comboBoxTryb_currentIndexChanged(int index);

private:
    Ui::DialogOnline *ui;
};

#endif // DIALOGONLINE_H
