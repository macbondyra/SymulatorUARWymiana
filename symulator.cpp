#include "symulator.h"
#include "ui_symulator.h"
#include <QVBoxLayout>
#include <QPixmap>
#include <QPainter>
#include <sstream>
#include <vector>
#include <QDebug>
#include <QVector>

std::vector<double> parseValues(const std::string& input) {
    std::vector<double> values;
    std::istringstream iss(input);
    std::string token;
    while (std::getline(iss, token, ',')) {
        try {
            values.push_back(std::stod(token));
        } catch (...) {
            std::cerr << "Nieprawidłowa wartość: " << token << std::endl;
        }
    }
    return values;
}

Symulator::Symulator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Symulator),
    timer(new QTimer(this))
{
    ui->setupUi(this);

    connect(ui->button_reset_pid, SIGNAL(clicked()), this, SLOT(on_button_reset_pid_clicked()));
    connect(ui->comboBox_mode, SIGNAL(currentIndexChanged(int)), this, SLOT(on_comboBox_mode_currentIndexChanged(int)));

    // Inicjalne ustawienie wartości
    ui->comboBox_mode->addItem("PRE_SUM");
    ui->comboBox_mode->addItem("POST_SUM");

    // Pobranie aktualnego trybu z kontrolera i ustawienie w ComboBox
    TrybCalkowania currentMode = uklad.getPIDMode(); // Musisz dodać tę funkcję w UkladSterowania
    int modeIndex = (currentMode == TrybCalkowania::PRE_SUM) ? 0 : 1;
    ui->comboBox_mode->setCurrentIndex(modeIndex);

    QStringList WartoscZadana ={"Skok jednostkowy","Sinusoidalny","Sygnał prostokątny"};    //Ustawianie tekstu dla tabeli Wartość Zadana
    foreach(QString item, WartoscZadana){
        ui->list_WartoscZadana->addItem(item);
    }
    connect(timer, SIGNAL(timeout()),this,SLOT(nextStep()));
    timer->setInterval(100);
    ui->button_stop->setEnabled(false);
    ui->button_reset->setEnabled(false);
    ui->spinbox_interval->setValue(timer->interval());

    ui->wykres->legend->setVisible(true);
    ui->wykres->addGraph();
    ui->wykres->addGraph();
    ui->wykres->graph(0)->setPen(QPen(Qt::blue));
    ui->wykres->graph(0)->setName("Wyjście układu");
    ui->wykres->graph(1)->setPen(QPen(Qt::green));
    ui->wykres->graph(1)->setName("Wartość zadana");

    ui->wykres->xAxis->setLabel("Czas");
    ui->wykres->xAxis->setRange(0,100);

    ui->wykres->yAxis->setLabel("Wartosc");
    ui->wykres->yAxis->setRange(uklad.get_max()*0.5*-1,std::max(uklad.get_wartoscZadana(), obecnaWartosc));



    ui->wykres_kontroler->legend->setVisible(true);
    ui->wykres_kontroler->addGraph();
    ui->wykres_kontroler->addGraph();
    ui->wykres_kontroler->addGraph();
    ui->wykres_kontroler->graph(0)->setPen(QPen(Qt::green));
    ui->wykres_kontroler->graph(0)->setName("Część Proporcjonalna");
    ui->wykres_kontroler->graph(1)->setPen(QPen(Qt::red));
    ui->wykres_kontroler->graph(1)->setName("Część Całkująca");
    ui->wykres_kontroler->graph(2)->setPen(QPen(Qt::yellow));
    ui->wykres_kontroler->graph(2)->setName("Część Różniczkująca");

    ui->wykres_kontroler->xAxis->setLabel("Czas");
    ui->wykres_kontroler->xAxis->setRange(0,100);

    ui->wykres_kontroler->yAxis->setLabel("Wartosc");
    ui->wykres_kontroler->yAxis->setRange(-1,uklad.get_max());

    ui->wykres_uchyb->legend->setVisible(true);
    ui->wykres_uchyb->addGraph();
    ui->wykres_uchyb->graph(0)->setName("Uchyb");
    ui->wykres_uchyb->xAxis->setLabel("Czas");
    ui->wykres_uchyb->xAxis->setRange(0,100);

    ui->wykres_uchyb->yAxis->setLabel("Wartosc");
    ui->wykres_uchyb->yAxis->setRange(-1,uklad.get_wartoscZadana()-obecnaWartosc+0.2*(uklad.get_wartoscZadana()-obecnaWartosc));


    ui->wykres_kontroler_suma->legend->setVisible(true);
    ui->wykres_kontroler_suma->addGraph();
    ui->wykres_kontroler_suma->graph(0)->setName("Wyjście kontrolera");
    ui->wykres_kontroler_suma->xAxis->setLabel("Czas");
    ui->wykres_kontroler_suma->xAxis->setRange(0,100);

    ui->wykres_kontroler_suma->yAxis->setLabel("Wartosc");
    ui->wykres_kontroler_suma->yAxis->setRange(-1,uklad.get_max());

}

Symulator::~Symulator()
{
    delete ui;
}

//void Symulator::liczenie(){
//    uklad.setARX(A,B,ui->spinbox_k->value());
//    uklad.setPID(ui->spinbox_P->value(),ui->spinbox_I->value(),ui->spinbox_D->value(),ui->spinbox_minimum->value(),ui->spinbox_maksimum->value());
//    uklad.setWartosc(WartoscZadana,ui->spinbox_maksimumY->value(),ui->spinbox_okres->value());
   // std::vector<double> wyniki = uklad.symulacja(100);
//}

void Symulator::nextStep()
{
    obecnaWartosc = uklad.symulacja(krok);
    krok++;

    //uklad.setARX(A, B, szum, delay);
    uklad.setPID(ui->spinbox_P->value(), ui->spinbox_I->value(), ui->spinbox_D->value(),
                 ui->spinbox_minimum->value(), ui->spinbox_maksimum->value());
    uklad.setWartosc(WartoscZadana, ui->spinbox_maksimumY->value(), ui->spinbox_okres->value(), ui->spinBox_wypelnienie->value());





    //rysowanie wykresów dalej
    ui->wykres->graph(0)->addData(krok, obecnaWartosc);
    ui->wykres->graph(1)->addData(krok, uklad.get_wartoscZadana());

    if(krok>100){

        rozmiar_wykresu_min.erase(rozmiar_wykresu_min.begin());
        rozmiar_wykresu_kontroler_min.erase(rozmiar_wykresu_kontroler_min.begin());
        rozmiar_wykresu_suma_min.erase(rozmiar_wykresu_suma_min.begin());
        rozmiar_wykresu_uchyb_min.erase(rozmiar_wykresu_uchyb_min.begin());

        rozmiar_wykresu_max.erase(rozmiar_wykresu_max.begin());
        rozmiar_wykresu_kontroler_max.erase(rozmiar_wykresu_kontroler_max.begin());
        rozmiar_wykresu_suma_max.erase(rozmiar_wykresu_suma_max.begin());
        rozmiar_wykresu_uchyb_max.erase(rozmiar_wykresu_uchyb_max.begin());
    }
    rozmiar_wykresu_max.push_back(std::max(uklad.get_max(),obecnaWartosc));
    rozmiar_wykresu_min.push_back(obecnaWartosc);
    rozmiar_wykresu_kontroler_max.push_back(std::max(std::max(uklad.getBlad(), uklad.getCalka()), uklad.getPochodna()));
    rozmiar_wykresu_kontroler_min.push_back(std::min(-1.0,abs(std::min(std::min(uklad.getBlad(), uklad.getCalka()), uklad.getPochodna()))*-1.2));
    rozmiar_wykresu_uchyb_min.push_back(std::min(-1.0,((uklad.get_wartoscZadana()-obecnaWartosc)*1.2)));
    rozmiar_wykresu_uchyb_max.push_back(std::max(1.0,((uklad.get_wartoscZadana()-obecnaWartosc)*1.2)));
    rozmiar_wykresu_suma_min.push_back(std::min(-1.0,((uklad.getWyjscie())*1.2)));
    rozmiar_wykresu_suma_max.push_back(std::max(1.0,((uklad.getWyjscie())*1.2)));


    ui->wykres->yAxis->setRange((*std::min_element(rozmiar_wykresu_min.begin(),rozmiar_wykresu_min.end()))-1,(*std::max_element(rozmiar_wykresu_max.begin(),rozmiar_wykresu_max.end()))*1.2);
    if (krok>100)
        ui->wykres->xAxis->setRange(krok-100,krok+100);
    ui->wykres->replot();

    ui->wykres_kontroler->graph(0)->addData(krok, uklad.getBlad());
    ui->wykres_kontroler->graph(1)->addData(krok, uklad.getCalka());
    ui->wykres_kontroler->graph(2)->addData(krok, uklad.getPochodna());


    ui->wykres_kontroler->yAxis->setRange( (*std::min_element(rozmiar_wykresu_kontroler_min.begin(),rozmiar_wykresu_kontroler_min.end()))-1 ,(*std::max_element(rozmiar_wykresu_kontroler_max.begin(),rozmiar_wykresu_kontroler_max.end()))*1.2);
    if (krok>100)
        ui->wykres_kontroler->xAxis->setRange(krok-100,krok+100);
    ui->wykres_kontroler->replot();



    ui->wykres_uchyb->graph(0)->addData(krok, uklad.get_wartoscZadana()-obecnaWartosc);
    ui->wykres_uchyb->yAxis->setRange(*std::min_element(rozmiar_wykresu_uchyb_min.begin(),rozmiar_wykresu_uchyb_min.end())-1 ,(*std::max_element(rozmiar_wykresu_uchyb_max.begin(),rozmiar_wykresu_uchyb_max.end()))*1.2);
    if (krok>100)
        ui->wykres_uchyb->xAxis->setRange(krok-100,krok+100);
    ui->wykres_uchyb->replot();


    ui->wykres_kontroler_suma->graph(0)->addData(krok, uklad.getWyjscie());
    ui->wykres_kontroler_suma->yAxis->setRange(*std::min_element(rozmiar_wykresu_suma_min.begin(),rozmiar_wykresu_suma_min.end())-1,(*std::max_element(rozmiar_wykresu_suma_max.begin(),rozmiar_wykresu_suma_max.end()))*1.2);
    if (krok>100)
        ui->wykres_kontroler_suma->xAxis->setRange(krok-100,krok+100);
    ui->wykres_kontroler_suma->replot();
}

/*void Symulator::on_spinbox_A_valueChanged(double value)
{
    A.push_back(value);
    //uklad.setA(A);
}


void Symulator::on_spinbox_B_valueChanged(double value)
{
    B.push_back(value);
    //uklad.setB(B);
}*/

void Symulator::on_list_WartoscZadana_currentRowChanged(int currentRow)
{
    if(currentRow==0) WartoscZadana=rodzajeWartosci::skok;
    else
    (currentRow==1)? WartoscZadana=rodzajeWartosci::sinus : WartoscZadana=rodzajeWartosci::kwadrat;
    //uklad.setRodzaj(WartoscZadana);
}


void Symulator::on_button_zapisz_clicked()
{
    uklad.zapiszPlik("arx.txt", "pid.txt", "wartosc.txt");
}


void Symulator::on_button_wczytaj_clicked()
{
    uklad.wczytajPlik("arx.txt", "pid.txt", "wartosc.txt");

    //przypisanie wartosci do przyciskow
    ui->spinbox_P->setValue(uklad.get_kp());
    ui->spinbox_I->setValue(uklad.get_ki());
    ui->spinbox_D->setValue(uklad.get_kd());

    //ui->lineEdit_A->setText(QString::fromStdString(uklad.get_lastA()));
    //ui->lineEdit_B->setText(QString::fromStdString(uklad.get_lastB()));

    ui->spinbox_minimum->setValue(uklad.get_dolnyLimit());
    ui->spinbox_maksimum->setValue(uklad.get_gornyLimit());
    ui->spinbox_maksimumY->setValue(uklad.get_max());
    ui->spinbox_okres->setValue(uklad.get_okres());
    ui->list_WartoscZadana->setCurrentRow(uklad.get_rodzajLiczba());
}


void Symulator::on_button_reset_clicked()
{
    ui->button_start->setEnabled(true);
    ui->button_stop->setEnabled(false);
    ui->button_reset->setEnabled(false);
    timer->stop();

    uklad.reset();
    krok = 0;

    rozmiar_wykresu_min.clear();
    rozmiar_wykresu_kontroler_min.clear();
    rozmiar_wykresu_suma_min.clear();
    rozmiar_wykresu_uchyb_min.clear();
    rozmiar_wykresu_max.clear();
    rozmiar_wykresu_kontroler_max.clear();
    rozmiar_wykresu_suma_max.clear();
    rozmiar_wykresu_uchyb_max.clear();

    uklad.setARX(A, B, szum, delay);
    uklad.setPID(ui->spinbox_P->value(),ui->spinbox_I->value(),ui->spinbox_D->value(),ui->spinbox_minimum->value(),ui->spinbox_maksimum->value());
    uklad.setWartosc(WartoscZadana,ui->spinbox_maksimumY->value(),ui->spinbox_okres->value(), ui->spinBox_wypelnienie->value());

    ui->wykres->graph(0)->data()->clear();
    ui->wykres->graph(1)->data()->clear();

    ui->wykres->xAxis->setLabel("Czas");
    ui->wykres->xAxis->setRange(0,100);

    ui->wykres->yAxis->setLabel("Wartosc");
    ui->wykres->yAxis->setRange(0,uklad.get_max());
    ui->wykres->replot();

    ui->wykres_kontroler->graph(0)->data()->clear();
    ui->wykres_kontroler->graph(1)->data()->clear();
    ui->wykres_kontroler->graph(2)->data()->clear();

    ui->wykres_kontroler->xAxis->setLabel("Czas");
    ui->wykres_kontroler->xAxis->setRange(0,100);

    ui->wykres_kontroler->yAxis->setLabel("Wartosc");
    ui->wykres_kontroler->yAxis->setRange(0,uklad.get_max());
    ui->wykres_kontroler->replot();

    ui->wykres_uchyb->graph(0)->data()->clear();

    ui->wykres_uchyb->xAxis->setLabel("Czas");
    ui->wykres_uchyb->xAxis->setRange(0,100);

    ui->wykres_uchyb->yAxis->setLabel("Wartosc");
    ui->wykres_uchyb->yAxis->setRange(0,uklad.get_max());
    ui->wykres_uchyb->replot();

    ui->wykres_kontroler_suma->graph(0)->data()->clear();

    ui->wykres_kontroler_suma->xAxis->setLabel("Czas");
    ui->wykres_kontroler_suma->xAxis->setRange(0,100);

    ui->wykres_kontroler_suma->yAxis->setLabel("Wartosc");
    ui->wykres_kontroler_suma->yAxis->setRange(0,uklad.get_max());
    ui->wykres_kontroler_suma->replot();
}


void Symulator::on_button_start_clicked()
{
    ui->button_reset->setEnabled(true);
    ui->button_start->setEnabled(false);
    ui->button_stop->setEnabled(true);
    timer->start();

    uklad.setARX(A, B, szum, delay);
    uklad.setPID(ui->spinbox_P->value(), ui->spinbox_I->value(), ui->spinbox_D->value(),
    ui->spinbox_minimum->value(), ui->spinbox_maksimum->value());
    uklad.setWartosc(WartoscZadana, ui->spinbox_maksimumY->value(), ui->spinbox_okres->value(), ui->spinBox_wypelnienie->value());



}



void Symulator::on_button_stop_clicked()
{
    ui->button_start->setEnabled(true);
    ui->button_stop->setEnabled(false);
    timer->stop();
}



void Symulator::on_spinbox_interval_valueChanged(double arg1)
{
    timer->setInterval(arg1);
}




void Symulator::on_spinbox_maksimumY_valueChanged(double arg1)
{
        ui->wykres->yAxis->setRange(0,arg1+0.2*arg1);
}


void Symulator::on_checkBox_stateChanged(int arg1)
{
    uklad.setFiltr(arg1);
}

void Symulator::on_lineEdit_A_editingFinished() {

}

void Symulator::on_lineEdit_B_editingFinished() {

}

void Symulator::on_button_reset_pid_clicked()
{
    uklad.reset();
    ui->spinbox_P->setValue(uklad.get_kp());
    ui->spinbox_I->setValue(uklad.get_ki());
    ui->spinbox_D->setValue(uklad.get_kd());
}

void Symulator::on_comboBox_mode_currentIndexChanged(int index)
{
    TrybCalkowania mode = (index == 0) ? TrybCalkowania::PRE_SUM : TrybCalkowania::POST_SUM;
    uklad.setPID(uklad.get_kp(), uklad.get_ki(), uklad.get_kd());
    uklad.setTrybCalkowania(mode);
}




void Symulator::on_arxModify_clicked()
{
    dialog = new Dialog(nullptr);
    int result = dialog->exec();
    if(result)
    {
        A = dialog->getA();
        B = dialog->getB();
        szum = dialog->getSzum();
        delay = dialog->getDelay();
        uklad.setARX(A, B, szum, delay);
    }


    delete dialog;
}


//void Symulator::on_spinbox_k_valueChanged(double arg1)
//{

//}

