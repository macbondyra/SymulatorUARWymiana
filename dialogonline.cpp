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
    QString ip = ui->ipPart1->text() + "." + ui->ipPart2->text() + "." + ui->ipPart3->text() + "."
                 + ui->ipPart4->text();
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

bool DialogOnline::getCzyTrybJednostronny()
{
    if(ui->trybJednostronny->isChecked()){
        return true;
    }
    else{
        return false;
    }
}

void DialogOnline::on_comboBoxTryb_currentIndexChanged(int index)
{
    if (index == 1) {
        ui->groupBoxPID->hide();
    }
    if (index == 0) {
        ui->groupBoxPID->show();
    }
}
