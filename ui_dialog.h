/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *BDialog;
    QLineEdit *ADialog;
    QDoubleSpinBox *szumDialog;
    QLabel *label_5;
    QSpinBox *spinbox_delay;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(122, 62, 178, 145));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 0, 0, 1, 4);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 1, 0, 1, 2);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 3, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        BDialog = new QLineEdit(layoutWidget);
        BDialog->setObjectName("BDialog");

        gridLayout->addWidget(BDialog, 4, 1, 1, 3);

        ADialog = new QLineEdit(layoutWidget);
        ADialog->setObjectName("ADialog");

        gridLayout->addWidget(ADialog, 3, 1, 1, 3);

        szumDialog = new QDoubleSpinBox(layoutWidget);
        szumDialog->setObjectName("szumDialog");

        gridLayout->addWidget(szumDialog, 1, 2, 1, 2);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 2, 0, 1, 2);

        spinbox_delay = new QSpinBox(layoutWidget);
        spinbox_delay->setObjectName("spinbox_delay");

        gridLayout->addWidget(spinbox_delay, 2, 2, 1, 2);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Dialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Dialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "Format: 0.0, 0.6, 0.4...", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "Szum:", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "A:", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "B:", nullptr));
        label_5->setText(QCoreApplication::translate("Dialog", "Op\303\263\305\272nienie:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
