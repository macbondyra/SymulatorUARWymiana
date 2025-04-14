#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    std::vector<double> getA();
    std::vector<double> getB();
    double getSzum();
    int getDelay();

private slots:
    void on_szumDialog_valueChanged(double arg1);

    void on_ADialog_editingFinished();

    void on_BDialog_editingFinished();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
