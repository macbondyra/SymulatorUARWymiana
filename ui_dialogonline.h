/********************************************************************************
** Form generated from reading UI file 'dialogonline.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGONLINE_H
#define UI_DIALOGONLINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogOnline
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelIp;
    QHBoxLayout *ipLayout;
    QLineEdit *ipPart1;
    QLabel *dotLabel1;
    QLineEdit *ipPart2;
    QLabel *dotLabel2;
    QLineEdit *ipPart3;
    QLabel *dotLabel3;
    QLineEdit *ipPart4;
    QLabel *labelPort;
    QLineEdit *lineEditPort;
    QLabel *labelCombo;
    QComboBox *comboBoxTryb;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogOnline)
    {
        if (DialogOnline->objectName().isEmpty())
            DialogOnline->setObjectName("DialogOnline");
        DialogOnline->resize(551, 300);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DialogOnline->sizePolicy().hasHeightForWidth());
        DialogOnline->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(DialogOnline);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelIp = new QLabel(DialogOnline);
        labelIp->setObjectName("labelIp");

        formLayout->setWidget(0, QFormLayout::LabelRole, labelIp);

        ipLayout = new QHBoxLayout();
        ipLayout->setObjectName("ipLayout");
        ipPart1 = new QLineEdit(DialogOnline);
        ipPart1->setObjectName("ipPart1");
        ipPart1->setMaxLength(3);

        ipLayout->addWidget(ipPart1);

        dotLabel1 = new QLabel(DialogOnline);
        dotLabel1->setObjectName("dotLabel1");

        ipLayout->addWidget(dotLabel1);

        ipPart2 = new QLineEdit(DialogOnline);
        ipPart2->setObjectName("ipPart2");
        ipPart2->setMaxLength(3);

        ipLayout->addWidget(ipPart2);

        dotLabel2 = new QLabel(DialogOnline);
        dotLabel2->setObjectName("dotLabel2");

        ipLayout->addWidget(dotLabel2);

        ipPart3 = new QLineEdit(DialogOnline);
        ipPart3->setObjectName("ipPart3");
        ipPart3->setMaxLength(3);

        ipLayout->addWidget(ipPart3);

        dotLabel3 = new QLabel(DialogOnline);
        dotLabel3->setObjectName("dotLabel3");

        ipLayout->addWidget(dotLabel3);

        ipPart4 = new QLineEdit(DialogOnline);
        ipPart4->setObjectName("ipPart4");
        ipPart4->setMaxLength(3);

        ipLayout->addWidget(ipPart4);


        formLayout->setLayout(0, QFormLayout::FieldRole, ipLayout);

        labelPort = new QLabel(DialogOnline);
        labelPort->setObjectName("labelPort");

        formLayout->setWidget(1, QFormLayout::LabelRole, labelPort);

        lineEditPort = new QLineEdit(DialogOnline);
        lineEditPort->setObjectName("lineEditPort");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditPort);

        labelCombo = new QLabel(DialogOnline);
        labelCombo->setObjectName("labelCombo");

        formLayout->setWidget(2, QFormLayout::LabelRole, labelCombo);

        comboBoxTryb = new QComboBox(DialogOnline);
        comboBoxTryb->setObjectName("comboBoxTryb");

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBoxTryb);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(DialogOnline);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DialogOnline);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DialogOnline, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DialogOnline, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DialogOnline);
    } // setupUi

    void retranslateUi(QDialog *DialogOnline)
    {
        DialogOnline->setWindowTitle(QCoreApplication::translate("DialogOnline", "Ustawienia Po\305\202\304\205czenia", nullptr));
        labelIp->setText(QCoreApplication::translate("DialogOnline", "Adres IP:", nullptr));
        ipPart1->setInputMask(QString());
        dotLabel1->setText(QCoreApplication::translate("DialogOnline", ".", nullptr));
        ipPart2->setInputMask(QString());
        dotLabel2->setText(QCoreApplication::translate("DialogOnline", ".", nullptr));
        ipPart3->setInputMask(QString());
        dotLabel3->setText(QCoreApplication::translate("DialogOnline", ".", nullptr));
        ipPart4->setInputMask(QString());
        labelPort->setText(QCoreApplication::translate("DialogOnline", "Port:", nullptr));
        labelCombo->setText(QCoreApplication::translate("DialogOnline", "Opcja:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogOnline: public Ui_DialogOnline {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGONLINE_H
