#include "dialog.h"
#include "ui_dialog.h"
#include "symulator.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}



std::vector<double> Dialog::getA()
{
    std::string inputA = ui->ADialog->text().toStdString();
    std::vector<double> newA = parseValues(inputA);
    return newA;
}

std::vector<double> Dialog::getB()
{
    std::string inputB = ui->BDialog->text().toStdString();
    std::vector<double> newB = parseValues(inputB);
    return newB;
}

double Dialog::getSzum()
{
    return ui->szumDialog->value();
}

void Dialog::on_szumDialog_valueChanged(double arg1)
{

}


void Dialog::on_ADialog_editingFinished()
{

}


void Dialog::on_BDialog_editingFinished()
{


}

int Dialog::getDelay()
{
    return ui->spinbox_delay->value();
}
