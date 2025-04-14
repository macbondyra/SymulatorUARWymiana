#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <vector>
#include <deque>
#include <random>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <sstream>
#include <memory>

class ARXModel {
private:
    std::vector<double> A;
    std::vector<double> B;
    std::deque<double> u_hist;
    std::deque<double> y_hist;
    std::default_random_engine generator;
    std::unique_ptr<std::normal_distribution<double>> dystrybucja;
    double sigma;
    int opoznienie = 1;

public:
    ARXModel(const std::vector<double>& a, const std::vector<double>& b, double szum = 0.0)
        : A(a), B(b), sigma(szum) {
        if (sigma > 0.0) {
            dystrybucja = std::make_unique<std::normal_distribution<double>>(0.0, sigma);
        } else {
            dystrybucja = nullptr;
        }
        size_t maxSize = std::max(A.size(), B.size()) + opoznienie;
        u_hist = std::deque<double>(maxSize, 0.0);
        y_hist = std::deque<double>(maxSize, 0.0);
    }

    ARXModel() : sigma(0.0) {
        A = { 0.0 };
        B = { 0.0 };
        dystrybucja = nullptr;
        size_t maxSize = std::max(A.size(), B.size()) + opoznienie;
        u_hist = std::deque<double>(maxSize, 0.0);
        y_hist = std::deque<double>(maxSize, 0.0);
    }

    void setModel(const std::vector<double>& a, const std::vector<double>& b, double szum = 0.0, int opoznienieTransportowe = 1) {
        A = a;
        B = b;
        sigma = szum;
        opoznienie = std::max(1, opoznienieTransportowe);

        if (sigma > 0.0) {
            dystrybucja = std::make_unique<std::normal_distribution<double>>(0.0, sigma);
        } else {
            dystrybucja = nullptr;
        }

        size_t maxSize = std::max(A.size(), B.size()) + opoznienie;
        u_hist = std::deque<double>(maxSize, 0.0);
        y_hist = std::deque<double>(maxSize, 0.0);
    }

    void updateCoefficients(const std::vector<double>& newA, const std::vector<double>& newB) {
        A = newA;
        B = newB;
        size_t maxSize = std::max(A.size(), B.size()) + opoznienie;
        u_hist = std::deque<double>(maxSize, 0.0);
        y_hist = std::deque<double>(maxSize, 0.0);
    }

    std::string get_lastA() const {
        if (A.empty()) return "0.0";
        std::stringstream sa;
        for (auto i : A) sa << i << ", ";
        return sa.str();
    }

    std::string get_lastB() const {
        if (B.empty()) return "0.0";
        std::stringstream sb;
        for (auto i : B) sb << i << ", ";
        return sb.str();
    }

    double krok(double input) {
        u_hist.pop_front();
        u_hist.push_back(input);

        double szum = dystrybucja ? (*dystrybucja)(generator) : 0.0;
        double y_k = 0.0;

        for (size_t i = 0; i < A.size(); i++) {
            if (y_hist.size() > i)
                y_k -= A[i] * y_hist[y_hist.size() - 1 - i];
        }

        for (size_t i = 0; i < B.size(); i++) {
            size_t index = u_hist.size() - 1 - i - opoznienie;
            if (index < u_hist.size()) {
                y_k += B[i] * u_hist[index];
            }
        }

        y_k += szum;

        y_hist.pop_front();
        y_hist.push_back(y_k);

        return y_k;
    }

    void zapiszText(const std::string& nazwaPliku) {
        std::ofstream ofs(nazwaPliku);
        if (!ofs) return;

        ofs << A.size() << "\n";
        for (const auto& a : A) ofs << a << "\n";
        ofs << B.size() << "\n";
        for (const auto& b : B) ofs << b << "\n";
        ofs << 0.0 << "\n" << sigma << "\n";
    }

    void wczytajText(const std::string& nazwaPliku) {
        std::ifstream ifs(nazwaPliku);
        if (!ifs) return;

        size_t rozmiarA, rozmiarB;
        double wartA, wartB;
        ifs >> rozmiarA;
        A.clear(); A.reserve(rozmiarA);
        for (size_t i = 0; i < rozmiarA; ++i) {
            ifs >> wartA;
            A.push_back(wartA);
        }

        ifs >> rozmiarB;
        B.clear(); B.reserve(rozmiarB);
        for (size_t i = 0; i < rozmiarB; ++i) {
            ifs >> wartB;
            B.push_back(wartB);
        }

        double mean, stddev;
        ifs >> mean >> stddev;
        sigma = stddev;
        dystrybucja = (sigma > 0.0) ? std::make_unique<std::normal_distribution<double>>(mean, sigma) : nullptr;
    }

    void reset() {
        //A.clear();
        //B.clear();
        u_hist.clear();
        y_hist.clear();
        size_t maxSize = std::max(A.size(), B.size()) + opoznienie;
        u_hist = std::deque<double>(maxSize, 0.0);
        y_hist = std::deque<double>(maxSize, 0.0);
    }
};

template <typename T>
T filtr(T wartosc, T dolny, T gorny) {
    return std::max(dolny, std::min(wartosc, gorny));
}

enum class rodzajeWartosci
{
    skok = 0,
    sinus = 1,
    kwadrat = 2,
};

class WartZadana
{
public:
    WartZadana(rodzajeWartosci typ = rodzajeWartosci::skok, double maximum = 1, int cykl = 20, int wyp = 100)
    {
        rodzaj = typ;
        min = 0;
        max = maximum;
        okres = cykl;
        wypelnienie = wyp;
    };

    void setWart(rodzajeWartosci typ = rodzajeWartosci::skok, double maximum = 1, int cykl = 20, int wyp = 100)
    {
        rodzaj = typ;
        min = 0;
        max = maximum;
        okres = cykl;
        wypelnienie = wyp;
    }

    double obliczWartosc(int krok)
    {
        if (rodzaj == rodzajeWartosci::skok)
        {
            return max;
        }
        else if (rodzaj == rodzajeWartosci::kwadrat)
        {
            if (krok % (okres/2) == 0)
            {
                minMax = !minMax;
            }
            if (minMax == 0)
            {
                return min;
            }
            else
            {
                if((krok % (okres/2)) > (okres/2*0.01*wypelnienie))
                    return min;
                else
                    return max;

            }
        }
        else
        {
            double amplituda = (max - min) / 2;
            double przesuniecie = (max + min) / 2;
            double kat = (static_cast<double>(krok) / okres) * 2.0 * 3.14;
            return amplituda * sin(kat) + przesuniecie;
        }
    }

    void zapiszText(const std::string& filename) {
        std::ofstream ofs(filename);
        if (!ofs) return;
        ofs << min << "\n" << max << "\n" << okres << "\n" << static_cast<int>(rodzaj) << "\n";

    }

    void wczytajText(const std::string& nazwaPliku) {
        std::ifstream ifs(nazwaPliku);
        if (!ifs) return;
        int typ;
        ifs >> min >> max >> okres >> typ;
        rodzaj = static_cast<rodzajeWartosci>(typ);
    }

    int get_rodzajLiczba() const { return (int)rodzaj;}
    double get_max() const{return max;}
    int get_okres() const{return okres;}

    void reset(){
        setWart(rodzajeWartosci::skok,0.0,0);
    }


private:
    rodzajeWartosci rodzaj = rodzajeWartosci::skok;
    double min = -1, max = 1;
    int okres;
    bool minMax = 0;
    int wypelnienie = 50;
};

enum class TrybCalkowania {
    PRE_SUM,
    POST_SUM
};

class PIDController {
private:
    double kp, ki, kd;
    double calka, bladPoprzedzajacy;
    double dolnyLimit, gornyLimit;
    bool flagaPrzeciwNasyceniowa;
    double blad;
    double pochodna;
    double wyjscie;
    double maxCalka;
    double maxPochodna;
    TrybCalkowania integralMode;

public:
    PIDController(double kp, double ki, double kd,
                  double dolnyLimit = -1.0, double gornyLimit = 1.0,
                  TrybCalkowania mode = TrybCalkowania::POST_SUM)
        : kp(kp), ki(ki), kd(kd),
        calka(0.0), bladPoprzedzajacy(0.0),
        dolnyLimit(dolnyLimit), gornyLimit(gornyLimit),
        flagaPrzeciwNasyceniowa(false),
        blad(0.0), pochodna(0.0), wyjscie(0.0),
        maxCalka(10.0), maxPochodna(10.0),
        integralMode(mode)
    {
    }

    PIDController()
        : kp(0.0), ki(0.0), kd(0.0),
        calka(0.0), bladPoprzedzajacy(0.0),
        dolnyLimit(-1.0), gornyLimit(1.0),
        flagaPrzeciwNasyceniowa(false),
        blad(0.0), pochodna(0.0), wyjscie(0.0),
        maxCalka(10.0), maxPochodna(10.0),
        integralMode(TrybCalkowania::POST_SUM)
    {
    }

    double get_kp() const { return kp; }
    double get_ki() const { return ki; }
    double get_kd() const { return kd; }
    double get_dolnyLimit() const { return dolnyLimit; }
    double get_gornyLimit() const { return gornyLimit; }

    double getCalka() const {
        return (integralMode == TrybCalkowania::PRE_SUM) ? calka : ki * calka;
    }

    double getBlad() const { return kp * blad; }
    double getPochodna() const { return kd * pochodna; }
    double getWyjscie() const { return wyjscie; }

    void ustawLimity(double lower, double upper) {
        dolnyLimit = lower;
        gornyLimit = upper;
    }

    void setKontroler(double _kp, double _ki, double _kd) {
        kp = _kp;
        ki = _ki;
        kd = _kd;
    }

    void setFlagaPrzeciwnasyceniowa(bool flag) {
        flagaPrzeciwNasyceniowa = flag;
    }

    void setTrybCalkowania(TrybCalkowania mode) {
        integralMode = mode;
        reset();
    }

    void reset() {
        calka = 0.0;
        bladPoprzedzajacy = 0.0;
        blad = 0.0;
        pochodna = 0.0;
        wyjscie = 0.0;
    }

    template <typename T>
    T filtr(T value, T lower, T upper) {
        return std::max(lower, std::min(value, upper));
    }

    double oblicz(double ustawWartosc, double wartoscProcesu, double dt)
    {
        if (dt <= 0.0) {
            dt = 1.0;
        }

        double dtI = (ki != 0.0) ? 2.0 : dt;
        double dtD = (kd != 0.0) ? 0.5 : dt;

        blad = ustawWartosc - wartoscProcesu;

        if (integralMode == TrybCalkowania::PRE_SUM) {
            calka += ki * blad * dtI;
        } else {
            calka += blad * dtI;
        }

        calka = filtr(calka, -maxCalka, maxCalka);

        pochodna = (blad - bladPoprzedzajacy) / dtD;
        pochodna = filtr(pochodna, -maxPochodna, maxPochodna);

        bladPoprzedzajacy = blad;

        double integralContribution =
            (integralMode == TrybCalkowania::PRE_SUM) ? calka : (ki * calka);

        wyjscie = kp * blad + integralContribution + kd * pochodna;

        if (flagaPrzeciwNasyceniowa) {
            wyjscie = filtr(wyjscie, dolnyLimit, gornyLimit);
        }

        return wyjscie;
    }

    void zapiszText(const std::string& filename) {
        std::ofstream ofs(filename);
        if (!ofs) return;
        ofs << kp << "\n" << ki << "\n" << kd << "\n";
        ofs << dolnyLimit << "\n" << gornyLimit << "\n";
        ofs << flagaPrzeciwNasyceniowa << "\n";
        ofs << maxCalka << "\n" << maxPochodna << "\n";
        ofs << static_cast<int>(integralMode) << "\n";
    }

    void wczytajText(const std::string& nazwaPliku) {
        std::ifstream ifs(nazwaPliku);
        if (!ifs) return;
        int modeInt;
        ifs >> kp >> ki >> kd;
        ifs >> dolnyLimit >> gornyLimit;
        ifs >> flagaPrzeciwNasyceniowa;
        ifs >> maxCalka >> maxPochodna;
        ifs >> modeInt;
        integralMode = static_cast<TrybCalkowania>(modeInt);
    }

    TrybCalkowania getTrybCalkowania() const {
        return integralMode;
    }
};

class UkladSterowania
{
public:

    UkladSterowania()
    {};
    ~UkladSterowania()
    {};
    void setPID(double kp, double ki, double kd, double dolnyLimit = -1.0, double gornyLimit = 1.0)
    {
        kontroler.setKontroler(kp, ki, kd);
        kontroler.ustawLimity(dolnyLimit, gornyLimit);
    }

    void setARX(const std::vector<double>& a, const std::vector<double>& b, double szum = 0.01, int opoznienie = 1)
    {
        model.setModel(a, b, szum, opoznienie);
    }

    void setWartosc(rodzajeWartosci rodzaj, double max, int okres, int wyp)
    {
        wartosc.setWart(rodzaj, max, okres, wyp);
    }
    void setFiltr(bool filtr)
    {
        kontroler.setFlagaPrzeciwnasyceniowa(filtr);
    }
    void zapiszPlik(const std::string& nazwaPlikuARX, const std::string& nazwaPlikuPID, const std::string& nazwaPlikuWartosc)
    {
        model.zapiszText(nazwaPlikuARX);
        kontroler.zapiszText(nazwaPlikuPID);
        wartosc.zapiszText(nazwaPlikuWartosc);
    }
    void wczytajPlik(const std::string& nazwaPlikuARX, const std::string& nazwaPlikuPID, const std::string& nazwaPlikuWartosc)
    {
        model.wczytajText(nazwaPlikuARX);
        kontroler.wczytajText(nazwaPlikuPID);
        wartosc.wczytajText(nazwaPlikuWartosc);
    }
    double symulacja(size_t krok)
    {

        wartoscZadana = wartosc.obliczWartosc(krok);
        double sygnalKontrolny = kontroler.oblicz(wartoscZadana, wartoscProcesu, 1.0);
        wartoscProcesu = model.krok(sygnalKontrolny);
        /*
            std::cerr << "Krok: " << i
                << " -> Sterowanie: " << sygnalKontrolny
                << " Wyjscie: " << wartoscProcesu
                << std::endl;
                */
        obliczone = wartoscProcesu;
        return obliczone;
    }

    void reset(){
        kontroler.reset();
        model.reset();
        wartosc.reset();
        wartoscProcesu = 0.0;
        obliczone = 0.0;
        wartoscZadana=0.0;
    }

    void resetPID() {
        kontroler.reset();
    }

    void setTrybCalkowania(TrybCalkowania mode) {
        kontroler.setTrybCalkowania(mode);
    }

    TrybCalkowania getPIDMode() const {
        return kontroler.getTrybCalkowania();
    }


    int get_rodzajLiczba() const { return wartosc.get_rodzajLiczba();}
    double get_max() const{return wartosc.get_max();}
    double get_kp() const{return kontroler.get_kp();}
    double get_ki() const{return kontroler.get_ki();}
    double get_kd() const{return kontroler.get_kd();}
    double getCalka() const{return kontroler.getCalka();}
    double getBlad() const{return kontroler.getBlad();}
    double getWyjscie() const{return kontroler.getWyjscie();}
    double getPochodna() const{return kontroler.getPochodna();}
    double get_dolnyLimit() const{return kontroler.get_dolnyLimit();}
    double get_gornyLimit() const{return kontroler.get_gornyLimit();}
    std::string get_lastA() const{return model.get_lastA();}
    std::string get_lastB() const{return model.get_lastB();}
    int get_okres() const{return wartosc.get_okres();}
    double get_wartoscZadana() const{return wartoscZadana;}
private:
    ARXModel model;
    PIDController kontroler;
    WartZadana wartosc;
    double wartoscProcesu = 0.0;
    double wartoscZadana = 0.0;
    double obliczone;
};

