#include "dialogonline.h"
#include "ui_dialogonline.h"

DialogOnline::DialogOnline(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogOnline)
{
    ui->setupUi(this);
}

DialogOnline::~DialogOnline()
{
    delete ui;
}

