#ifndef SYMULATOR_H
#define SYMULATOR_H

#include <QMainWindow>
#include <QTimer>
#include "klasy.h"
#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Symulator;
}
QT_END_NAMESPACE


    std::vector<double> parseValues(const std::string& input);

class Symulator : public QMainWindow
{
    Q_OBJECT

public:
    Symulator(QWidget *parent = nullptr);
    ~Symulator();
    //void liczenie();
private slots:

    void nextStep();

    //void on_spinbox_A_valueChanged(double value);

    //void on_spinbox_B_valueChanged(double value);

    void on_list_WartoscZadana_currentRowChanged(int currentRow);

    void on_button_zapisz_clicked();

    void on_button_wczytaj_clicked();

    void on_button_reset_clicked();

    void on_button_start_clicked();

    void on_button_stop_clicked();

    void on_spinbox_interval_valueChanged(double arg1);

    void on_spinbox_maksimumY_valueChanged(double arg1);

    void on_checkBox_stateChanged(int arg1);

    void on_lineEdit_A_editingFinished(); // Obsługa dla współczynników A

    void on_lineEdit_B_editingFinished(); // Obsługa dla współczynników B

    void on_button_reset_pid_clicked();

    void on_comboBox_mode_currentIndexChanged(int index);

    void on_arxModify_clicked();




private:
    Ui::Symulator *ui;
    QTimer *timer = nullptr;
    UkladSterowania uklad;
    std::vector<double> A;
    std::vector<double> B;
    double szum;
    rodzajeWartosci WartoscZadana;
    int krok = 0;
    double obecnaWartosc;
    Dialog *dialog;
    int delay = 1;
    std::vector<double> rozmiar_wykresu_min, rozmiar_wykresu_max;
    std::vector<double> rozmiar_wykresu_kontroler_min,rozmiar_wykresu_kontroler_max;
    std::vector<double> rozmiar_wykresu_suma_min,rozmiar_wykresu_suma_max;
    std::vector<double> rozmiar_wykresu_uchyb_min,rozmiar_wykresu_uchyb_max;

    double wykres_kontroler_min=0, wykres_kontroler_max=0;


    friend Dialog;
};
#endif // SYMULATOR_H
