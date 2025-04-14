/********************************************************************************
** Form generated from reading UI file 'symulator.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYMULATOR_H
#define UI_SYMULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Symulator
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_17;
    QVBoxLayout *verticalLayout_9;
    QCustomPlot *wykres;
    QCustomPlot *wykres_uchyb;
    QVBoxLayout *verticalLayout_10;
    QCustomPlot *wykres_kontroler;
    QCustomPlot *wykres_kontroler_suma;
    QHBoxLayout *horizontalLayout_16;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *button_start;
    QPushButton *button_stop;
    QPushButton *button_reset;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_interval;
    QLabel *label_ms;
    QDoubleSpinBox *spinbox_interval;
    QHBoxLayout *horizontalLayout_15;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_PID;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_P;
    QLabel *label_I;
    QLabel *label_D;
    QVBoxLayout *verticalLayout_5;
    QDoubleSpinBox *spinbox_P;
    QDoubleSpinBox *spinbox_I;
    QDoubleSpinBox *spinbox_D;
    QPushButton *button_reset_pid;
    QComboBox *comboBox_mode;
    QGroupBox *groupBox_ARX;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_6;
    QPushButton *arxModify;
    QGroupBox *groupBox_WartoscZadana;
    QHBoxLayout *horizontalLayout_14;
    QHBoxLayout *horizontalLayout_13;
    QListWidget *list_WartoscZadana;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_maksimumY;
    QLabel *label_okres;
    QLabel *label;
    QVBoxLayout *verticalLayout_7;
    QDoubleSpinBox *spinbox_maksimumY;
    QSpinBox *spinbox_okres;
    QSpinBox *spinBox_wypelnienie;
    QGroupBox *groupBox_UstawieniaFiltra;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_minimum;
    QDoubleSpinBox *spinbox_minimum;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_maksimum;
    QDoubleSpinBox *spinbox_maksimum;
    QCheckBox *checkBox;
    QVBoxLayout *verticalLayout_2;
    QPushButton *button_zapisz;
    QPushButton *button_wczytaj;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Symulator)
    {
        if (Symulator->objectName().isEmpty())
            Symulator->setObjectName("Symulator");
        Symulator->resize(1203, 831);
        centralwidget = new QWidget(Symulator);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        wykres = new QCustomPlot(centralwidget);
        wykres->setObjectName("wykres");
        wykres->setMinimumSize(QSize(0, 256));

        verticalLayout_9->addWidget(wykres);

        wykres_uchyb = new QCustomPlot(centralwidget);
        wykres_uchyb->setObjectName("wykres_uchyb");
        wykres_uchyb->setMinimumSize(QSize(0, 256));

        verticalLayout_9->addWidget(wykres_uchyb);


        horizontalLayout_17->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        wykres_kontroler = new QCustomPlot(centralwidget);
        wykres_kontroler->setObjectName("wykres_kontroler");
        wykres_kontroler->setMinimumSize(QSize(0, 256));

        verticalLayout_10->addWidget(wykres_kontroler);

        wykres_kontroler_suma = new QCustomPlot(centralwidget);
        wykres_kontroler_suma->setObjectName("wykres_kontroler_suma");
        wykres_kontroler_suma->setMinimumSize(QSize(0, 256));

        verticalLayout_10->addWidget(wykres_kontroler_suma);


        horizontalLayout_17->addLayout(verticalLayout_10);


        gridLayout->addLayout(horizontalLayout_17, 0, 0, 1, 1);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        horizontalLayout_16->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        button_start = new QPushButton(centralwidget);
        button_start->setObjectName("button_start");
        QFont font;
        font.setBold(true);
        button_start->setFont(font);

        horizontalLayout_4->addWidget(button_start);

        button_stop = new QPushButton(centralwidget);
        button_stop->setObjectName("button_stop");
        button_stop->setFont(font);

        horizontalLayout_4->addWidget(button_stop);

        button_reset = new QPushButton(centralwidget);
        button_reset->setObjectName("button_reset");
        button_reset->setFont(font);

        horizontalLayout_4->addWidget(button_reset);


        horizontalLayout_16->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_interval = new QLabel(centralwidget);
        label_interval->setObjectName("label_interval");
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        label_interval->setFont(font1);
        label_interval->setTextFormat(Qt::AutoText);
        label_interval->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_interval);

        label_ms = new QLabel(centralwidget);
        label_ms->setObjectName("label_ms");
        label_ms->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_ms);


        horizontalLayout_5->addLayout(verticalLayout_3);

        spinbox_interval = new QDoubleSpinBox(centralwidget);
        spinbox_interval->setObjectName("spinbox_interval");
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        spinbox_interval->setFont(font2);
        spinbox_interval->setDecimals(0);
        spinbox_interval->setMinimum(10.000000000000000);
        spinbox_interval->setMaximum(10000.000000000000000);

        horizontalLayout_5->addWidget(spinbox_interval);


        horizontalLayout_16->addLayout(horizontalLayout_5);


        gridLayout->addLayout(horizontalLayout_16, 1, 0, 1, 1);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(4);
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        horizontalLayout_15->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        groupBox_PID = new QGroupBox(centralwidget);
        groupBox_PID->setObjectName("groupBox_PID");
        groupBox_PID->setFont(font1);
        groupBox_PID->setAlignment(Qt::AlignCenter);
        horizontalLayout_6 = new QHBoxLayout(groupBox_PID);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        label_P = new QLabel(groupBox_PID);
        label_P->setObjectName("label_P");
        label_P->setFont(font1);
        label_P->setTextFormat(Qt::AutoText);
        label_P->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_P);

        label_I = new QLabel(groupBox_PID);
        label_I->setObjectName("label_I");
        label_I->setFont(font1);
        label_I->setTextFormat(Qt::AutoText);
        label_I->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_I);

        label_D = new QLabel(groupBox_PID);
        label_D->setObjectName("label_D");
        label_D->setFont(font1);
        label_D->setTextFormat(Qt::AutoText);
        label_D->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_D);


        horizontalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setSizeConstraint(QLayout::SetFixedSize);
        spinbox_P = new QDoubleSpinBox(groupBox_PID);
        spinbox_P->setObjectName("spinbox_P");
        spinbox_P->setMinimum(-99.989999999999995);

        verticalLayout_5->addWidget(spinbox_P);

        spinbox_I = new QDoubleSpinBox(groupBox_PID);
        spinbox_I->setObjectName("spinbox_I");
        spinbox_I->setMinimum(0.000000000000000);

        verticalLayout_5->addWidget(spinbox_I);

        spinbox_D = new QDoubleSpinBox(groupBox_PID);
        spinbox_D->setObjectName("spinbox_D");
        spinbox_D->setMinimum(-99.989999999999995);

        verticalLayout_5->addWidget(spinbox_D);


        horizontalLayout_6->addLayout(verticalLayout_5);

        button_reset_pid = new QPushButton(groupBox_PID);
        button_reset_pid->setObjectName("button_reset_pid");

        horizontalLayout_6->addWidget(button_reset_pid);

        comboBox_mode = new QComboBox(groupBox_PID);
        comboBox_mode->setObjectName("comboBox_mode");

        horizontalLayout_6->addWidget(comboBox_mode);


        horizontalLayout_3->addWidget(groupBox_PID);

        groupBox_ARX = new QGroupBox(centralwidget);
        groupBox_ARX->setObjectName("groupBox_ARX");
        groupBox_ARX->setFont(font1);
        groupBox_ARX->setAlignment(Qt::AlignCenter);
        horizontalLayout_10 = new QHBoxLayout(groupBox_ARX);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setSizeConstraint(QLayout::SetFixedSize);
        arxModify = new QPushButton(groupBox_ARX);
        arxModify->setObjectName("arxModify");

        verticalLayout_6->addWidget(arxModify);


        horizontalLayout_10->addLayout(verticalLayout_6);


        horizontalLayout_3->addWidget(groupBox_ARX);

        groupBox_WartoscZadana = new QGroupBox(centralwidget);
        groupBox_WartoscZadana->setObjectName("groupBox_WartoscZadana");
        groupBox_WartoscZadana->setFont(font1);
        groupBox_WartoscZadana->setAlignment(Qt::AlignCenter);
        horizontalLayout_14 = new QHBoxLayout(groupBox_WartoscZadana);
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        horizontalLayout_13->setSizeConstraint(QLayout::SetFixedSize);
        list_WartoscZadana = new QListWidget(groupBox_WartoscZadana);
        list_WartoscZadana->setObjectName("list_WartoscZadana");
        list_WartoscZadana->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_13->addWidget(list_WartoscZadana);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        horizontalLayout_12->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setSizeConstraint(QLayout::SetFixedSize);
        label_maksimumY = new QLabel(groupBox_WartoscZadana);
        label_maksimumY->setObjectName("label_maksimumY");
        label_maksimumY->setFont(font1);
        label_maksimumY->setTextFormat(Qt::AutoText);
        label_maksimumY->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_maksimumY);

        label_okres = new QLabel(groupBox_WartoscZadana);
        label_okres->setObjectName("label_okres");
        label_okres->setFont(font1);
        label_okres->setTextFormat(Qt::AutoText);
        label_okres->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_okres);

        label = new QLabel(groupBox_WartoscZadana);
        label->setObjectName("label");
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(true);
        label->setFont(font3);

        verticalLayout_8->addWidget(label);


        horizontalLayout_12->addLayout(verticalLayout_8);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setSizeConstraint(QLayout::SetFixedSize);
        spinbox_maksimumY = new QDoubleSpinBox(groupBox_WartoscZadana);
        spinbox_maksimumY->setObjectName("spinbox_maksimumY");

        verticalLayout_7->addWidget(spinbox_maksimumY);

        spinbox_okres = new QSpinBox(groupBox_WartoscZadana);
        spinbox_okres->setObjectName("spinbox_okres");

        verticalLayout_7->addWidget(spinbox_okres);

        spinBox_wypelnienie = new QSpinBox(groupBox_WartoscZadana);
        spinBox_wypelnienie->setObjectName("spinBox_wypelnienie");
        spinBox_wypelnienie->setMinimum(1);
        spinBox_wypelnienie->setMaximum(100);
        spinBox_wypelnienie->setValue(100);

        verticalLayout_7->addWidget(spinBox_wypelnienie);


        horizontalLayout_12->addLayout(verticalLayout_7);


        horizontalLayout_13->addLayout(horizontalLayout_12);


        horizontalLayout_14->addLayout(horizontalLayout_13);


        horizontalLayout_3->addWidget(groupBox_WartoscZadana);

        groupBox_UstawieniaFiltra = new QGroupBox(centralwidget);
        groupBox_UstawieniaFiltra->setObjectName("groupBox_UstawieniaFiltra");
        groupBox_UstawieniaFiltra->setFont(font1);
        groupBox_UstawieniaFiltra->setAlignment(Qt::AlignCenter);
        horizontalLayout_11 = new QHBoxLayout(groupBox_UstawieniaFiltra);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        label_minimum = new QLabel(groupBox_UstawieniaFiltra);
        label_minimum->setObjectName("label_minimum");
        label_minimum->setFont(font1);
        label_minimum->setTextFormat(Qt::AutoText);
        label_minimum->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_minimum);

        spinbox_minimum = new QDoubleSpinBox(groupBox_UstawieniaFiltra);
        spinbox_minimum->setObjectName("spinbox_minimum");
        spinbox_minimum->setMinimum(-99.989999999999995);

        horizontalLayout->addWidget(spinbox_minimum);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        label_maksimum = new QLabel(groupBox_UstawieniaFiltra);
        label_maksimum->setObjectName("label_maksimum");
        label_maksimum->setFont(font1);
        label_maksimum->setTextFormat(Qt::AutoText);
        label_maksimum->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_maksimum);

        spinbox_maksimum = new QDoubleSpinBox(groupBox_UstawieniaFiltra);
        spinbox_maksimum->setObjectName("spinbox_maksimum");
        spinbox_maksimum->setMinimum(-99.989999999999995);

        horizontalLayout_2->addWidget(spinbox_maksimum);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_11->addLayout(verticalLayout);

        checkBox = new QCheckBox(groupBox_UstawieniaFiltra);
        checkBox->setObjectName("checkBox");

        horizontalLayout_11->addWidget(checkBox);


        horizontalLayout_3->addWidget(groupBox_UstawieniaFiltra);


        horizontalLayout_15->addLayout(horizontalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        button_zapisz = new QPushButton(centralwidget);
        button_zapisz->setObjectName("button_zapisz");
        button_zapisz->setFont(font);

        verticalLayout_2->addWidget(button_zapisz);

        button_wczytaj = new QPushButton(centralwidget);
        button_wczytaj->setObjectName("button_wczytaj");
        button_wczytaj->setFont(font);

        verticalLayout_2->addWidget(button_wczytaj);


        horizontalLayout_15->addLayout(verticalLayout_2);

        horizontalLayout_15->setStretch(1, 1);

        gridLayout->addLayout(horizontalLayout_15, 2, 0, 1, 1);

        Symulator->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Symulator);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1203, 21));
        Symulator->setMenuBar(menubar);
        statusbar = new QStatusBar(Symulator);
        statusbar->setObjectName("statusbar");
        Symulator->setStatusBar(statusbar);
        QWidget::setTabOrder(button_zapisz, button_wczytaj);
        QWidget::setTabOrder(button_wczytaj, spinbox_D);
        QWidget::setTabOrder(spinbox_D, spinbox_I);
        QWidget::setTabOrder(spinbox_I, spinbox_P);
        QWidget::setTabOrder(spinbox_P, list_WartoscZadana);
        QWidget::setTabOrder(list_WartoscZadana, button_start);
        QWidget::setTabOrder(button_start, spinbox_maksimumY);
        QWidget::setTabOrder(spinbox_maksimumY, spinbox_okres);
        QWidget::setTabOrder(spinbox_okres, spinbox_maksimum);
        QWidget::setTabOrder(spinbox_maksimum, spinbox_minimum);
        QWidget::setTabOrder(spinbox_minimum, checkBox);
        QWidget::setTabOrder(checkBox, button_reset);
        QWidget::setTabOrder(button_reset, button_stop);
        QWidget::setTabOrder(button_stop, spinbox_interval);

        retranslateUi(Symulator);

        QMetaObject::connectSlotsByName(Symulator);
    } // setupUi

    void retranslateUi(QMainWindow *Symulator)
    {
        Symulator->setWindowTitle(QCoreApplication::translate("Symulator", "Symulator", nullptr));
        button_start->setText(QCoreApplication::translate("Symulator", "Start", nullptr));
        button_stop->setText(QCoreApplication::translate("Symulator", "Stop", nullptr));
        button_reset->setText(QCoreApplication::translate("Symulator", "Reset", nullptr));
        label_interval->setText(QCoreApplication::translate("Symulator", "Interwa\305\202", nullptr));
        label_ms->setText(QCoreApplication::translate("Symulator", "(w ms)", nullptr));
        groupBox_PID->setTitle(QCoreApplication::translate("Symulator", "PID", nullptr));
        label_P->setText(QCoreApplication::translate("Symulator", "P", nullptr));
        label_I->setText(QCoreApplication::translate("Symulator", "I", nullptr));
        label_D->setText(QCoreApplication::translate("Symulator", "D", nullptr));
        button_reset_pid->setText(QCoreApplication::translate("Symulator", "Reset", nullptr));
        groupBox_ARX->setTitle(QCoreApplication::translate("Symulator", "ARX", nullptr));
        arxModify->setText(QCoreApplication::translate("Symulator", "Modyfikuj", nullptr));
        groupBox_WartoscZadana->setTitle(QCoreApplication::translate("Symulator", "Warto\305\233\304\207 Zadana", nullptr));
        label_maksimumY->setText(QCoreApplication::translate("Symulator", "Max Y", nullptr));
        label_okres->setText(QCoreApplication::translate("Symulator", "Okres", nullptr));
        label->setText(QCoreApplication::translate("Symulator", "Wype\305\202nienie (w %)", nullptr));
        groupBox_UstawieniaFiltra->setTitle(QCoreApplication::translate("Symulator", "Ustawienia filtra", nullptr));
        label_minimum->setText(QCoreApplication::translate("Symulator", "Minimum", nullptr));
        label_maksimum->setText(QCoreApplication::translate("Symulator", "Maksimum", nullptr));
        checkBox->setText(QCoreApplication::translate("Symulator", "U\305\274y\304\207 filtra?", nullptr));
        button_zapisz->setText(QCoreApplication::translate("Symulator", "Zapisz do pliku", nullptr));
        button_wczytaj->setText(QCoreApplication::translate("Symulator", "Wczytaj z pliku", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Symulator: public Ui_Symulator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYMULATOR_H
