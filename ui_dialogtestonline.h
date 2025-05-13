/********************************************************************************
** Form generated from reading UI file 'dialogtestonline.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGTESTONLINE_H
#define UI_DIALOGTESTONLINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dialogTestOnline
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QRadioButton *TestServer;
    QRadioButton *TestNadajnik;

    void setupUi(QDialog *dialogTestOnline)
    {
        if (dialogTestOnline->objectName().isEmpty())
            dialogTestOnline->setObjectName("dialogTestOnline");
        dialogTestOnline->resize(400, 300);
        buttonBox = new QDialogButtonBox(dialogTestOnline);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        widget = new QWidget(dialogTestOnline);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(60, 90, 94, 52));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        TestServer = new QRadioButton(widget);
        TestServer->setObjectName("TestServer");

        verticalLayout->addWidget(TestServer);

        TestNadajnik = new QRadioButton(widget);
        TestNadajnik->setObjectName("TestNadajnik");

        verticalLayout->addWidget(TestNadajnik);


        retranslateUi(dialogTestOnline);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, dialogTestOnline, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, dialogTestOnline, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(dialogTestOnline);
    } // setupUi

    void retranslateUi(QDialog *dialogTestOnline)
    {
        dialogTestOnline->setWindowTitle(QCoreApplication::translate("dialogTestOnline", "Dialog", nullptr));
        TestServer->setText(QCoreApplication::translate("dialogTestOnline", "TestServer", nullptr));
        TestNadajnik->setText(QCoreApplication::translate("dialogTestOnline", "TestNadajnik", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialogTestOnline: public Ui_dialogTestOnline {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGTESTONLINE_H
