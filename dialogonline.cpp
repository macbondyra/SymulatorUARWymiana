#include "dialogonline.h"
#include "ui_dialogonline.h"

DialogOnline::DialogOnline(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogOnline)
{
    ui->setupUi(this);
    ui->comboBoxTryb->addItem("PID");
    ui->comboBoxTryb->addItem("ARX");
}

DialogOnline::~DialogOnline()
{
    delete ui;
}

QString DialogOnline::getIp()
{
    QString ip =
        ui->ipPart1->text() + "." +
        ui->ipPart2->text() + "." +
        ui->ipPart3->text() + "." +
        ui->ipPart4->text();
    return ip;
}

quint16 DialogOnline::getPort()
{
    return ui->lineEditPort->text().toUShort();
}

int DialogOnline::getTryb()
{
    int wybor = ui->comboBoxTryb->currentIndex();
    return wybor;
}

