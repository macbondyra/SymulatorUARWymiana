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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogOnline
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBoxPID;
    QFormLayout *formLayoutPID;
    QLabel *labelIp;
    QHBoxLayout *ipLayout;
    QLineEdit *ipPart1;
    QLabel *dotLabel1;
    QLineEdit *ipPart2;
    QLabel *dotLabel2;
    QLineEdit *ipPart3;
    QLabel *dotLabel3;
    QLineEdit *ipPart4;
    QLabel *labelEmptyPID;
    QRadioButton *trybJednostronny;
    QLabel *labelEmptyPID2;
    QRadioButton *trybObustronny;
    QFormLayout *formLayoutRemaining;
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
        groupBoxPID = new QGroupBox(DialogOnline);
        groupBoxPID->setObjectName("groupBoxPID");
        formLayoutPID = new QFormLayout(groupBoxPID);
        formLayoutPID->setObjectName("formLayoutPID");
        labelIp = new QLabel(groupBoxPID);
        labelIp->setObjectName("labelIp");

        formLayoutPID->setWidget(0, QFormLayout::LabelRole, labelIp);

        ipLayout = new QHBoxLayout();
        ipLayout->setObjectName("ipLayout");
        ipPart1 = new QLineEdit(groupBoxPID);
        ipPart1->setObjectName("ipPart1");
        ipPart1->setMaxLength(3);
        ipPart1->setMaximumWidth(40);

        ipLayout->addWidget(ipPart1);

        dotLabel1 = new QLabel(groupBoxPID);
        dotLabel1->setObjectName("dotLabel1");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dotLabel1->sizePolicy().hasHeightForWidth());
        dotLabel1->setSizePolicy(sizePolicy1);

        ipLayout->addWidget(dotLabel1);

        ipPart2 = new QLineEdit(groupBoxPID);
        ipPart2->setObjectName("ipPart2");
        ipPart2->setMaxLength(3);
        ipPart2->setMaximumWidth(40);

        ipLayout->addWidget(ipPart2);

        dotLabel2 = new QLabel(groupBoxPID);
        dotLabel2->setObjectName("dotLabel2");
        sizePolicy1.setHeightForWidth(dotLabel2->sizePolicy().hasHeightForWidth());
        dotLabel2->setSizePolicy(sizePolicy1);

        ipLayout->addWidget(dotLabel2);

        ipPart3 = new QLineEdit(groupBoxPID);
        ipPart3->setObjectName("ipPart3");
        ipPart3->setMaxLength(3);
        ipPart3->setMaximumWidth(40);

        ipLayout->addWidget(ipPart3);

        dotLabel3 = new QLabel(groupBoxPID);
        dotLabel3->setObjectName("dotLabel3");
        sizePolicy1.setHeightForWidth(dotLabel3->sizePolicy().hasHeightForWidth());
        dotLabel3->setSizePolicy(sizePolicy1);

        ipLayout->addWidget(dotLabel3);

        ipPart4 = new QLineEdit(groupBoxPID);
        ipPart4->setObjectName("ipPart4");
        ipPart4->setMaxLength(3);
        ipPart4->setMaximumWidth(40);

        ipLayout->addWidget(ipPart4);


        formLayoutPID->setLayout(0, QFormLayout::FieldRole, ipLayout);

        labelEmptyPID = new QLabel(groupBoxPID);
        labelEmptyPID->setObjectName("labelEmptyPID");

        formLayoutPID->setWidget(1, QFormLayout::LabelRole, labelEmptyPID);

        trybJednostronny = new QRadioButton(groupBoxPID);
        trybJednostronny->setObjectName("trybJednostronny");

        formLayoutPID->setWidget(1, QFormLayout::FieldRole, trybJednostronny);

        labelEmptyPID2 = new QLabel(groupBoxPID);
        labelEmptyPID2->setObjectName("labelEmptyPID2");

        formLayoutPID->setWidget(2, QFormLayout::LabelRole, labelEmptyPID2);

        trybObustronny = new QRadioButton(groupBoxPID);
        trybObustronny->setObjectName("trybObustronny");

        formLayoutPID->setWidget(2, QFormLayout::FieldRole, trybObustronny);


        verticalLayout->addWidget(groupBoxPID);

        formLayoutRemaining = new QFormLayout();
        formLayoutRemaining->setObjectName("formLayoutRemaining");
        labelPort = new QLabel(DialogOnline);
        labelPort->setObjectName("labelPort");

        formLayoutRemaining->setWidget(0, QFormLayout::LabelRole, labelPort);

        lineEditPort = new QLineEdit(DialogOnline);
        lineEditPort->setObjectName("lineEditPort");

        formLayoutRemaining->setWidget(0, QFormLayout::FieldRole, lineEditPort);

        labelCombo = new QLabel(DialogOnline);
        labelCombo->setObjectName("labelCombo");

        formLayoutRemaining->setWidget(1, QFormLayout::LabelRole, labelCombo);

        comboBoxTryb = new QComboBox(DialogOnline);
        comboBoxTryb->setObjectName("comboBoxTryb");

        formLayoutRemaining->setWidget(1, QFormLayout::FieldRole, comboBoxTryb);


        verticalLayout->addLayout(formLayoutRemaining);

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
        groupBoxPID->setTitle(QCoreApplication::translate("DialogOnline", "PID", nullptr));
        labelIp->setText(QCoreApplication::translate("DialogOnline", "Adres IP:", nullptr));
        ipPart1->setInputMask(QString());
        dotLabel1->setText(QCoreApplication::translate("DialogOnline", ".", nullptr));
        ipPart2->setInputMask(QString());
        dotLabel2->setText(QCoreApplication::translate("DialogOnline", ".", nullptr));
        ipPart3->setInputMask(QString());
        dotLabel3->setText(QCoreApplication::translate("DialogOnline", ".", nullptr));
        ipPart4->setInputMask(QString());
        labelEmptyPID->setText(QString());
        trybJednostronny->setText(QCoreApplication::translate("DialogOnline", "Tryb Jednostronny", nullptr));
        labelEmptyPID2->setText(QString());
        trybObustronny->setText(QCoreApplication::translate("DialogOnline", "Tryb Obustronny", nullptr));
        labelPort->setText(QCoreApplication::translate("DialogOnline", "Port:", nullptr));
        labelCombo->setText(QCoreApplication::translate("DialogOnline", "Opcja:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogOnline: public Ui_DialogOnline {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGONLINE_H
