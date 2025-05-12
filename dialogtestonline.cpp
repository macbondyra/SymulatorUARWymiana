#include "dialogtestonline.h"
#include "ui_dialogtestonline.h"

dialogTestOnline::dialogTestOnline(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dialogTestOnline)
{
    ui->setupUi(this);
}

dialogTestOnline::~dialogTestOnline()
{
    delete ui;
}

bool dialogTestOnline::getTryb()
{
    if(this->ui->TestServer->isChecked()){
        return false;
    }
    else if(this->ui->TestNadajnik->isChecked()){
        return true;
    }
}
