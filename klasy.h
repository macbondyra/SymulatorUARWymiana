#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <QMessageBox>
#include <QObject>
#include <QtNetwork>
#include <algorithm>
#include <cmath>
#include <deque>
#include <fstream>
#include <iostream>
#include <memory>
#include <random>
#include <sstream>
#include <vector>

class ARXModel
{
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
    ARXModel(const std::vector<double> &a, const std::vector<double> &b, double szum = 0.0)
        : A(a)
        , B(b)
        , sigma(szum)

    {
        if (sigma > 0.0) {
            dystrybucja = std::make_unique<std::normal_distribution<double>>(0.0, sigma);
        } else {
            dystrybucja = nullptr;
        }
        size_t maxSize = std::max(A.size(), B.size()) + opoznienie;
        u_hist = std::deque<double>(maxSize, 0.0);
        y_hist = std::deque<double>(maxSize, 0.0);
    }

    ARXModel()
        : sigma(0.0)

    {
        A = {0.0};
        B = {0.0};
        dystrybucja = nullptr;
        size_t maxSize = std::max(A.size(), B.size()) + opoznienie;
        u_hist = std::deque<double>(maxSize, 0.0);
        y_hist = std::deque<double>(maxSize, 0.0);
    }

    void setModel(const std::vector<double> &a,
                  const std::vector<double> &b,
                  double szum = 0.0,
                  int opoznienieTransportowe = 1)
    {
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

    void updateCoefficients(const std::vector<double> &newA, const std::vector<double> &newB)
    {
        A = newA;
        B = newB;
        size_t maxSize = std::max(A.size(), B.size()) + opoznienie;
        u_hist = std::deque<double>(maxSize, 0.0);
        y_hist = std::deque<double>(maxSize, 0.0);
    }

    std::string get_lastA() const
    {
        if (A.empty())
            return "0.0";
        std::stringstream sa;
        for (auto i : A)
            sa << i << ", ";
        return sa.str();
    }

    std::string get_lastB() const
    {
        if (B.empty())
            return "0.0";
        std::stringstream sb;
        for (auto i : B)
            sb << i << ", ";
        return sb.str();
    }

    double krok(double input)
    {
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

    void zapiszText(const std::string &nazwaPliku)
    {
        std::ofstream ofs(nazwaPliku);
        if (!ofs)
            return;

        ofs << A.size() << "\n";
        for (const auto &a : A)
            ofs << a << "\n";
        ofs << B.size() << "\n";
        for (const auto &b : B)
            ofs << b << "\n";
        ofs << 0.0 << "\n" << sigma << "\n";
    }

    void wczytajText(const std::string &nazwaPliku)
    {
        std::ifstream ifs(nazwaPliku);
        if (!ifs)
            return;

        size_t rozmiarA, rozmiarB;
        double wartA, wartB;
        ifs >> rozmiarA;
        A.clear();
        A.reserve(rozmiarA);
        for (size_t i = 0; i < rozmiarA; ++i) {
            ifs >> wartA;
            A.push_back(wartA);
        }

        ifs >> rozmiarB;
        B.clear();
        B.reserve(rozmiarB);
        for (size_t i = 0; i < rozmiarB; ++i) {
            ifs >> wartB;
            B.push_back(wartB);
        }

        double mean, stddev;
        ifs >> mean >> stddev;
        sigma = stddev;
        dystrybucja = (sigma > 0.0)
                          ? std::make_unique<std::normal_distribution<double>>(mean, sigma)
                          : nullptr;
    }

    void reset()
    {
        //A.clear();
        //B.clear();
        u_hist.clear();
        y_hist.clear();
        size_t maxSize = std::max(A.size(), B.size()) + opoznienie;
        u_hist = std::deque<double>(maxSize, 0.0);
        y_hist = std::deque<double>(maxSize, 0.0);
    }
    double getSzum(){return sigma;}
    int getDelay(){return opoznienie;}
    std::vector<double> getA(){return A;}
    std::vector<double> getB(){return B;}
};

template<typename T>
T filtr(T wartosc, T dolny, T gorny)
{
    return std::max(dolny, std::min(wartosc, gorny));
}

enum class rodzajeWartosci {
    skok = 0,
    sinus = 1,
    kwadrat = 2,
};

class WartZadana
{
public:
    WartZadana(rodzajeWartosci typ = rodzajeWartosci::skok,
               double maximum = 1,
               int cykl = 20,
               int wyp = 100)
    {
        rodzaj = typ;
        min = 0;
        max = maximum;
        okres = cykl;
        wypelnienie = wyp;
    };

    void setWart(rodzajeWartosci typ = rodzajeWartosci::skok,
                 double maximum = 1,
                 int cykl = 20,
                 int wyp = 100)
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

    void zapiszText(const std::string &filename)
    {
        std::ofstream ofs(filename);
        if (!ofs)
            return;
        ofs << min << "\n" << max << "\n" << okres << "\n" << static_cast<int>(rodzaj) << "\n";
    }

    void wczytajText(const std::string &nazwaPliku)
    {
        std::ifstream ifs(nazwaPliku);
        if (!ifs)
            return;
        int typ;
        ifs >> min >> max >> okres >> typ;
        rodzaj = static_cast<rodzajeWartosci>(typ);
    }

    int get_rodzajLiczba() const { return (int) rodzaj; }
    double get_max() const { return max; }
    int get_okres() const { return okres; }
    rodzajeWartosci get_rodzaj(){return rodzaj;}
    int get_wypelnienie(){return wypelnienie;}
    void reset() { setWart(rodzajeWartosci::skok, 0.0, 0); }

private:
    rodzajeWartosci rodzaj = rodzajeWartosci::skok;
    double min = -1, max = 1;
    int okres;
    bool minMax = 0;
    int wypelnienie = 50;
};

enum class TrybCalkowania { PRE_SUM, POST_SUM };

class PIDController
{
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
    PIDController(double kp,
                  double ki,
                  double kd,
                  double dolnyLimit = -1.0,
                  double gornyLimit = 1.0,
                  TrybCalkowania mode = TrybCalkowania::POST_SUM)
        : kp(kp)
        , ki(ki)
        , kd(kd)
        , calka(0.0)
        , bladPoprzedzajacy(0.0)
        , dolnyLimit(dolnyLimit)
        , gornyLimit(gornyLimit)
        , flagaPrzeciwNasyceniowa(false)
        , blad(0.0)
        , pochodna(0.0)
        , wyjscie(0.0)
        , maxCalka(10.0)
        , maxPochodna(10.0)
        , integralMode(mode)

    {}

    PIDController()
        : kp(0.0)
        , ki(0.0)
        , kd(0.0)
        , calka(0.0)
        , bladPoprzedzajacy(0.0)
        , dolnyLimit(-1.0)
        , gornyLimit(1.0)
        , flagaPrzeciwNasyceniowa(false)
        , blad(0.0)
        , pochodna(0.0)
        , wyjscie(0.0)
        , maxCalka(10.0)
        , maxPochodna(10.0)
        , integralMode(TrybCalkowania::POST_SUM)

    {}

    double get_kp() const { return kp; }
    double get_ki() const { return ki; }
    double get_kd() const { return kd; }
    double get_dolnyLimit() const { return dolnyLimit; }
    double get_gornyLimit() const { return gornyLimit; }

    double getCalka() const
    {
        return (integralMode == TrybCalkowania::PRE_SUM) ? calka : ki * calka;
    }

    double getBlad() const { return kp * blad; }
    double getPochodna() const { return kd * pochodna; }
    double getWyjscie() const { return wyjscie; }

    void ustawLimity(double lower, double upper)
    {
        dolnyLimit = lower;
        gornyLimit = upper;
    }

    void setKontroler(double _kp, double _ki, double _kd)
    {
        kp = _kp;
        ki = _ki;
        kd = _kd;
    }

    void setFlagaPrzeciwnasyceniowa(bool flag) { flagaPrzeciwNasyceniowa = flag; }

    void setTrybCalkowania(TrybCalkowania mode)
    {
        integralMode = mode;
        reset();
    }

    void reset()
    {
        calka = 0.0;
        bladPoprzedzajacy = 0.0;
        blad = 0.0;
        pochodna = 0.0;
        wyjscie = 0.0;
    }

    template<typename T>
    T filtr(T value, T lower, T upper)
    {
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

        double integralContribution = (integralMode == TrybCalkowania::PRE_SUM) ? calka
                                                                                : (ki * calka);

        wyjscie = kp * blad + integralContribution + kd * pochodna;

        if (flagaPrzeciwNasyceniowa) {
            wyjscie = filtr(wyjscie, dolnyLimit, gornyLimit);
        }

        return wyjscie;
    }

    void zapiszText(const std::string &filename)
    {
        std::ofstream ofs(filename);
        if (!ofs)
            return;
        ofs << kp << "\n" << ki << "\n" << kd << "\n";
        ofs << dolnyLimit << "\n" << gornyLimit << "\n";
        ofs << flagaPrzeciwNasyceniowa << "\n";
        ofs << maxCalka << "\n" << maxPochodna << "\n";
        ofs << static_cast<int>(integralMode) << "\n";
    }

    void wczytajText(const std::string &nazwaPliku)
    {
        std::ifstream ifs(nazwaPliku);
        if (!ifs)
            return;
        int modeInt;
        ifs >> kp >> ki >> kd;
        ifs >> dolnyLimit >> gornyLimit;
        ifs >> flagaPrzeciwNasyceniowa;
        ifs >> maxCalka >> maxPochodna;
        ifs >> modeInt;
        integralMode = static_cast<TrybCalkowania>(modeInt);
    }

    TrybCalkowania getTrybCalkowania() const { return integralMode; }
};

enum MessageType : qint8 {
    MSG_COMMAND  = 1,  // wysyła tylko bool czyDziala
    MSG_INTERVAL = 2,  // wysyła tylko int interval
    MSG_CONTROL  = 3,   // wysyła: double sygnalKontrolny, double wartoscZadana, int krok
    MSG_RESET = 4,
    MSG_MODE = 5,
    MSG_RESYNC=6
};

class Nadajnik : public QObject
{
    Q_OBJECT
public:
    Nadajnik(QObject *parent = nullptr,
             PIDController *controller = nullptr,
             int *krokUklad = nullptr,
             WartZadana *generatorWsk = nullptr)
        : QObject(parent)
        , kontroler(controller)
        , wartosc(generatorWsk)
        , socket(this)
        , ip("")
        , port(0)
        , connectionState(false)
        , wynik(0.0)
        , krok(krokUklad)
    {
        connect(&socket, &QTcpSocket::readyRead, this, &Nadajnik::socketReadyRead);
        connect(&socket, &QTcpSocket::connected, this, &Nadajnik::onConnected);
        connect(&socket, &QTcpSocket::disconnected, this, &Nadajnik::onDisconnected);
        connect(&socket,
                QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::errorOccurred),
                this,
                &Nadajnik::onConnectionError);
    }
    void setIP(const QString &ipnew) { ip = ipnew; }
    void setPort(quint16 portnew) { port = portnew; }
    void connectToHost() { socket.connectToHost(ip, port); }
    double getWynik() const { return wynik; }
    double getWynikPID() const {return wynikPID;}
    void setKontroler(PIDController *kontrolerNew) { kontroler = kontrolerNew; }
    void setGenerator(WartZadana *generatorNew) { wartosc = generatorNew; }
    void setKrok(int *krokNew) { krok = krokNew; }
    double getWartoscZadana(){return wartoscZadana;}
    void sendCommand(bool czyDziala)
    {
        if (!connectionState || socket.state() != QAbstractSocket::ConnectedState) {
            return;
        }
        QByteArray out;
        QDataStream stream(&out, QIODevice::WriteOnly);
        // 1 bajt = typ wiadomości, potem jedno bool
        stream << (qint8)MSG_COMMAND;
        stream << czyDziala;
        socket.write(out);
    }

    // Wysyła tylko zmianę interwału (int interval)
    void sendInterval(int interval)
    {
        if (!connectionState || socket.state() != QAbstractSocket::ConnectedState) {
            return;
        }
        QByteArray out;
        QDataStream stream(&out, QIODevice::WriteOnly);
        // 1 bajt = typ wiadomości, potem jeden int
        stream << (qint8)MSG_INTERVAL;
        stream << interval;
        socket.write(out);
    }
    void sendMode(){
        if (!connectionState || socket.state() != QAbstractSocket::ConnectedState) {
            return;
        }
        QByteArray out;
        QDataStream stream(&out, QIODevice::WriteOnly);
        // 1 bajt = typ wiadomości
        stream << (qint8)MSG_MODE;
        stream << czyTrybJednostronny;
        socket.write(out);
    }
    void sendReset(){
        if (!connectionState || socket.state() != QAbstractSocket::ConnectedState) {
            return;
        }
        QByteArray out;
        QDataStream stream(&out, QIODevice::WriteOnly);
        // 1 bajt = typ wiadomości
        stream << (qint8)MSG_RESET;
        socket.write(out);
    }

    // Wysyła sygnał sterujący (data = sygnalKontrolny), wartość zadaną i krok
    void sendControl(double data, double wartoscZadana, int krok)
    {
        if (!connectionState || socket.state() != QAbstractSocket::ConnectedState) {
            return;
        }
        QByteArray out;
        QDataStream stream(&out, QIODevice::WriteOnly);
        // 1 bajt = typ wiadomości, potem double, double, int
        stream << (qint8)MSG_CONTROL;
        stream << data;
        stream << wartoscZadana;
        stream << krok;
        socket.write(out);
    }
    void sendResync(){
        QByteArray out;
        QDataStream stream(&out, QIODevice::WriteOnly);
        // 1 bajt = typ wiadomości, potem double, double, int
        stream << (qint8)MSG_RESYNC;
        stream << *krok;
        stream << wynikPID;
        socket.write(out);
    }


    void rozlacz()
    {
        socket.disconnectFromHost();
        connectionState = false;
    }
    void setCzyTrybJednostronny(bool tryb){
        czyTrybJednostronny = tryb;
    }
    bool getCzyTrybJednostronny(){
        return czyTrybJednostronny;
    }
    bool getCzyZsynchronizowane(){return czyZsynchronizowane;}

    void resetNadajnik(){
        wynik=0;
        wartoscZadana=0;
        wynikPID=0;
    }

private:
    PIDController *kontroler;
    WartZadana *wartosc;
    QTcpSocket socket;

    QString getIp() const;
    quint16 getPort() const;
    QString ip;
    quint16 port;
    bool connectionState;
    double wynik = 0;
    double wyjscieARX;
    double wartoscZadana=0;
    double wynikPID=0;
    int *krok;
    bool czyTrybJednostronny;
    bool czyZsynchronizowane = true;
    const int PROG_BLEDU =1;

signals:
    void startTimer();
    void reset();
    void rozlaczono();
private slots:
    void socketReadyRead()
    {
        try {
            QByteArray response = socket.readAll();
            QDataStream in(&response, QIODevice::ReadOnly);
            double y;
            int krokOdbiornika;
            in >> y;
            in >> krokOdbiornika;
            /*if(std::abs(krokOdbiornika - *krok) <= PROG_BLEDU){
                qDebug()<<"SYNCHRONIZACJA";
                qDebug()<<"Krok odebrany"<<krokOdbiornika;
                qDebug()<<"Krok lokalny"<<*krok;
                czyZsynchronizowane=true;
            }
            else{
                qDebug()<<"Desync";
                qDebug()<<"Krok odebrany"<<krokOdbiornika;
                qDebug()<<"Krok lokalny"<<*krok;
                qDebug()<<"Wysyłam RESYNC";
                sendResync();
                czyZsynchronizowane=false;
            }*/
            // policz sygnał sterujący
            wynik = y;
            qDebug() << "PID wyliczył u =";       
        } catch (const std::exception &e) {
            QMessageBox::critical(nullptr, "Błąd", QString("Wystąpił wyjątek: %1").arg(e.what()));
        }
    }
    void onDisconnected(){
        {
            QMessageBox* msgBox = new QMessageBox;
            msgBox->setIcon(QMessageBox::Information);
            msgBox->setWindowTitle("Status");
            msgBox->setText("Rozłączono od ARX");
            msgBox->setStandardButtons(QMessageBox::Ok);
            msgBox->setWindowModality(Qt::WindowModal); // nie blokuje
            msgBox->setAttribute(Qt::WA_DeleteOnClose); // auto cleanup
            msgBox->show();
            connectionState = false;
            emit rozlaczono();
        }
    }
    void onConnected()
    {
        QMessageBox::information(nullptr, "Status", "Połączono pomyślnie z hostem!");
        connectionState = true;
        sendMode();
        sendReset();
        emit reset();
    }
    void onConnectionError(QAbstractSocket::SocketError socketError)
    {
        Q_UNUSED(socketError)

        QMessageBox* msgBox = new QMessageBox;
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowTitle("Status");
        msgBox->setText("Błąd połączenia: " + socket.errorString());
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->setWindowModality(Qt::NonModal); // nie blokuje
        msgBox->setAttribute(Qt::WA_DeleteOnClose); // auto cleanup
        msgBox->show();
    }
};

class Odbiornik : public QObject
{
    Q_OBJECT
public:
    Odbiornik(QObject *parent, ARXModel *model,int* krokUklad)
        : QObject(parent)
        , server(this)
        , ip("")
        , port(0)
        , connectionState(false)
        , modelARX(model)
        , clientSocket(nullptr)
        , krokUkladu(krokUklad)
    {
        connect(&server, &QTcpServer::newConnection, this, &Odbiornik::newClient);
    }
    void setIp(const QString &ipnew) { ip = ipnew; }
    void setPort(quint16 portnew) { port = portnew; }
    void startListening()
    {
        if (!server.isListening()) {
            if (server.listen(QHostAddress::Any, port)) {
                QMessageBox::information(nullptr, "Status", "Uruchomiono serwer");
                connectionState = true;
            } else {
                QMessageBox::critical(nullptr,
                                      "Błąd",
                                      "Nie udało się uruchomić serwera:\n" + server.errorString());
            }
        }
    }
    void stopListening()
    {
        if (server.isListening()) {
            server.close();
            QMessageBox* msgBox = new QMessageBox;
            msgBox->setIcon(QMessageBox::Information);
            msgBox->setWindowTitle("Status");
            msgBox->setText("Wyłączono serwer");
            msgBox->setStandardButtons(QMessageBox::Ok);
            msgBox->setWindowModality(Qt::NonModal); // nie blokuje
            msgBox->setAttribute(Qt::WA_DeleteOnClose); // auto cleanup
            msgBox->show();
            connectionState = false;
        }
    }
    void disconnectSocket(){
        if ((clientSocket && clientSocket->state() == QAbstractSocket::ConnectedState) ||
            (clientSocket && clientSocket->state() == QAbstractSocket::ConnectingState))
        {
            clientSocket->disconnectFromHost();
        }
    }
    void setModel(ARXModel *modelNew) { modelARX = modelNew; }
    int getOdebranyInterval(){return odebranyInterval;}
    void sendData(double data,int krok)
    {
        if (!clientSocket || clientSocket->state() != QAbstractSocket::ConnectedState) {
            qWarning() << "[Odbiornik] Nie można wysłać danych – brak połączenia";
            return;
        }
        QByteArray dataSent;
        QDataStream stream(&dataSent, QIODevice::WriteOnly);
        stream << data;
        stream << krok;
        if (clientSocket->isWritable())
            clientSocket->write(dataSent);
    }
    double getWyjsciePID() { return wyjsciePID; }
    double getWynik() { return wynik; }
    double getWartoscZadana(){return wartoscZadana;}
    bool getCzyDziala() const {
        return czyDziala;
    }

    void setCzyDziala(bool wartosc) {
        czyDziala = wartosc;
    }


    int getKrok() const {
        return krok;
    }

    void setKrok(int wartosc) {
        krok = wartosc;
    }
    bool getCzyTrybJednostronny(){
        return czyTrybJednostronny;
    }
    void setCzyTrybJednostronny(bool tryb){
        czyTrybJednostronny =tryb;
    }
    bool getCzyZsynchronizowane() const { return czyZsynchronizowane; }

    void onClientDisconnected()
    {
        connectionState = false;
        if (clientSocket) {
            clientSocket->disconnect();
            clientSocket->deleteLater();
            clientSocket = nullptr;
        }
        if (server.isListening()) {
            server.close();
        }
        emit rozlaczono();
    }
    void resetOdbiornik(){
        wynik=0;
        wartoscZadana=0;
        wyjsciePID=0;
        krok=0;
    }
signals:
    void startTimer();
    void stopTimer();
    void odebranoInterval();
    void resetObiekt();
    void schowajInterval();
    void nextStep();
    void rozlaczono();
private:
    QTcpServer server;
    QString ip;
    quint16 port;
    int odebranyInterval=0;
    bool connectionState;
    ARXModel *modelARX;
    QTcpSocket *clientSocket;
    double wyjsciePID;
    double wynik = 0;
    double wartoscZadana=0;
    bool czyDziala=false;
    int krok=0;
    int* krokUkladu=nullptr;
    QByteArray buffer;              // bufor do gromadzenia nadchodzących bajtów
    bool czyTrybJednostronny=false;
    bool czyZsynchronizowane=true;
    const int PROG_BLEDU=1;

private slots:
    void newClient()
    {
        clientSocket = server.nextPendingConnection();
        if (clientSocket) {
            connect(clientSocket, &QTcpSocket::readyRead, this, &Odbiornik::readData);
            connect(clientSocket, &QTcpSocket::disconnected, this, &Odbiornik::onClientDisconnected);
            QMessageBox::information(nullptr,
                                     "Status",
                                     "Nowy klient połączony: "
                                         + clientSocket->peerAddress().toString());
        }
    }
    void readData()
    {
        if (!clientSocket)
            return;

        QByteArray rawData = clientSocket->readAll();
        if (rawData.isEmpty())
            return;

        QDataStream in(&rawData, QIODevice::ReadOnly);

        // Może dojść kilka komunikatów naraz, więc odczytujemy w pętli:
        while (!in.atEnd()) {
            qint8 msgType;
            in >> msgType;

            switch (msgType) {
            case MSG_COMMAND: {
                // Otrzymujemy tylko bool czyDziala
                bool dzialaj;
                in >> dzialaj;
                czyDziala = dzialaj;
                if (!czyDziala && !czyTrybJednostronny)
                   // emit startTimer();
               // else
                    emit stopTimer();
                qDebug() << "[Odbiornik] Odebrano MSG_COMMAND:" << czyDziala;
                break;
            }
            case MSG_INTERVAL: {
                // Otrzymujemy tylko int interval
                int nowyInterval;
                in >> nowyInterval;
                odebranyInterval = nowyInterval;
                if(!czyTrybJednostronny){
                    odebranyInterval=odebranyInterval/2.0;
                }
                qDebug() << "[Odbiornik] Odebrano MSG_INTERVAL:" << odebranyInterval;
                emit odebranoInterval();
                break;
            }
            case MSG_CONTROL: {
                // Otrzymujemy: double sygnalKontrolny, double wartoscZadana, int krok
                double sygnalKontrolny, wartZad;
                int krokOdebrany;
                in >> sygnalKontrolny >> wartZad >> krokOdebrany;

                if (std::abs(krokOdebrany - *krokUkladu) <= PROG_BLEDU) {
                    czyZsynchronizowane = true;
                } else {
                    czyZsynchronizowane = false;
                    qDebug() << "[Odbiornik] Rozbieżność kroków! Lokalny krok ="
                             << krok << ", odebrany krokiem nadajnika ="
                             << krokOdebrany;
                }

                // Przypisujemy do pól
                wyjsciePID    = sygnalKontrolny;
                wartoscZadana = wartZad;
                krok = krokOdebrany;
               // wynik=modelARX->krok(wyjsciePID);
                //sendData(wynik,krok);
                // Teraz wywołujemy model ARX
                emit startTimer();
                if(czyTrybJednostronny){
                    emit nextStep();
                }
                qDebug() << "[Odbiornik] Odebrano MSG_CONTROL:"
                         << "u =" << sygnalKontrolny
                         << "wartZad =" << wartZad
                         << "krok =" << krokOdebrany
                         << "=> ARX y ="
                         << "| zsynchronizowane? =" << czyZsynchronizowane;
                break;
            }
            case MSG_RESET:{
                emit resetObiekt();
                break;
            }
            case MSG_MODE:{
                bool odebranyTryb;
                in>>odebranyTryb;
                czyTrybJednostronny=odebranyTryb;
                if(odebranyTryb==true){
                    emit schowajInterval();
                }
                break;
            }
            case MSG_RESYNC:{
                int krokOdebrany;
                double wynikPidOdebrany;
                in>>krokOdebrany;
                in>>wynikPidOdebrany;
                *krokUkladu = krokOdebrany;
                wyjsciePID=wynikPidOdebrany;
                modelARX->reset();
                break;
            }
            default:
                qDebug() << "[Odbiornik] Nieznany typ wiadomości:" << msgType;
                // Jeżeli trafi jakiś nieobsługiwany bajt, można przerwać pętlę,
                // by nie wpadać w nieskończoną pętlę odczytu.
                return;
            }
        }
    }
};

class UkladSterowania : QObject
{
    Q_OBJECT
public:
    UkladSterowania(QObject* parent = nullptr)
        : nadajnik(nullptr, &kontroler, &krok, &wartosc)
        , odbiornik(nullptr, &model,&krok) {};
    ~UkladSterowania() {};
    void setPID(double kp, double ki, double kd,
                double dolnyLimit = -1.0,
                double gornyLimit = 1.0)
    {
        PIDController &c = isOnlineModeON ? kontroler : kontroler_lokalny;
        c.setKontroler(kp, ki, kd);
        c.ustawLimity(dolnyLimit, gornyLimit);
    }

    void setARX(const std::vector<double> &a,
                const std::vector<double> &b,
                double szum = 0.01,
                int opoznienie = 1)
    {
        if (isOnlineModeON)
            model.setModel(a, b, szum, opoznienie);
        else
            model_lokalny.setModel(a, b, szum, opoznienie);
    }

    void setWartosc(rodzajeWartosci rodzaj,
                    double max,
                    int okres,
                    int wyp)
    {
        WartZadana &w = isOnlineModeON ? wartosc : wartosc_lokalna;
        w.setWart(rodzaj, max, okres, wyp);
    }
    void setFiltr(bool filtr)
    {
        PIDController &c = isOnlineModeON ? kontroler : kontroler_lokalny;
        c.setFlagaPrzeciwnasyceniowa(filtr);
    }
    void zapiszPlik(const std::string &nazwaPlikuARX,
                    const std::string &nazwaPlikuPID,
                    const std::string &nazwaPlikuWartosc)
    {
        model.zapiszText(nazwaPlikuARX);
        kontroler.zapiszText(nazwaPlikuPID);
        wartosc.zapiszText(nazwaPlikuWartosc);
    }
    void wczytajPlik(const std::string &nazwaPlikuARX,
                     const std::string &nazwaPlikuPID,
                     const std::string &nazwaPlikuWartosc)
    {
        model.wczytajText(nazwaPlikuARX);
        kontroler.wczytajText(nazwaPlikuPID);
        wartosc.wczytajText(nazwaPlikuWartosc);
    }
    void inkrementujKrok() { krok++; }
    void synchronizujZapasoweObiekty()
    {

    }
    void przejmijStanLokalny(){

        wartoscZadana = wartoscZadanaLokalna;
        sygnalKontrolny = sygnalKontrolnyLokalny;
        wartoscProcesu = wartoscProcesuLokalna;

    }
    double symulacja()
    {
        if (!isOnlineModeON) {
            // lokalnie
            wartoscZadana = wartosc_lokalna.obliczWartosc(krok);
            sygnalKontrolny = kontroler_lokalny.oblicz(wartoscZadana, wartoscProcesu, dt);
            wartoscProcesu = model_lokalny.krok(sygnalKontrolny);
            obliczone = wartoscProcesu;

            return obliczone;
        }
        // w trybie online nic tu nie musisz robić – sloty sieciowe już wymieniają dane
        else {
            if (trybPracyInstancji == 1) {
                sygnalKontrolny=odbiornik.getWyjsciePID();
                wartoscZadana=odbiornik.getWartoscZadana();
                wartoscProcesu=model.krok(sygnalKontrolny);
                odbiornik.sendData(wartoscProcesu,krok);
                //odbiornik.sendData(wartoscProcesu,krok);
                //Liczy lokalne wartosci po wysłaniu
                obliczone = wartoscProcesu;
                return obliczone;
            }

            else {
                wartoscZadana = wartosc.obliczWartosc((krok));
                sygnalKontrolny= kontroler.oblicz(wartoscZadana, nadajnik.getWynik(), dt);
                wartoscProcesu=nadajnik.getWynik();
                nadajnik.sendControl(sygnalKontrolny,wartoscZadana,krok);
                //Liczy lokalne wartosci po wysłaniu
                obliczone=wartoscProcesu;
                return obliczone;
            }
        }
    }

    void reset()
    {
        kontroler.reset();
        model.reset();
        wartosc.reset();
        wartoscProcesu = 0.0;
        obliczone = 0.0;
        wartoscZadana = 0.0;
        kontroler_lokalny.reset();
        model_lokalny.reset();
        wartosc_lokalna.reset();
        wartoscZadanaLokalna = 0.0;
        wartoscProcesuLokalna = 0.0;
        sygnalKontrolnyLokalny = 0.0;
    }

    void resetPID() { kontroler.reset(); }
    void setTrybPracyInstancji(bool tryb) { this->trybPracyInstancji = tryb; }
    void setIsOnlineModeON(bool mode) { this->isOnlineModeON = mode; }
    void setTrybCalkowania(TrybCalkowania mode)
    {
        PIDController &c = isOnlineModeON ? kontroler : kontroler_lokalny;
        c.setTrybCalkowania(mode);
    }

    TrybCalkowania getPIDMode() const {
        const PIDController &c = isOnlineModeON ? kontroler : kontroler_lokalny;
        return c.getTrybCalkowania();
    }

    int get_rodzajLiczba() const {
        const WartZadana &w = isOnlineModeON ? wartosc : wartosc_lokalna;
        return w.get_rodzajLiczba();
    }
    double get_max() const
    {
        const WartZadana &w = isOnlineModeON ? wartosc : wartosc_lokalna;
        return w.get_max();
    }
    double get_kp() const
    {
        const PIDController &c = isOnlineModeON ? kontroler : kontroler_lokalny;
        return c.get_kp();
    }
    double get_ki() const
    {
        const PIDController &c = isOnlineModeON ? kontroler : kontroler_lokalny;
        return c.get_ki();
    }
    double get_kd() const
    {
        const PIDController &c = isOnlineModeON ? kontroler : kontroler_lokalny;
        return c.get_kd();
    }
    double getCalka() const {
        const PIDController &c = isOnlineModeON ? kontroler : kontroler_lokalny;
        return c.getCalka();
    }
    double getBlad() const {
        const PIDController &c = isOnlineModeON ? kontroler : kontroler_lokalny;
        return c.getBlad();
    }
    double getWyjscie() const {
        const PIDController &c = isOnlineModeON ? kontroler : kontroler_lokalny;
        return c.getWyjscie();
    }
    double getPochodna() const {
        const PIDController &c = isOnlineModeON ? kontroler : kontroler_lokalny;
        return c.getPochodna();
    }
    double get_dolnyLimit() const {
        const PIDController &c = isOnlineModeON ? kontroler : kontroler_lokalny;
        return c.get_dolnyLimit();
    }
    double get_gornyLimit() const {
        const PIDController &c = isOnlineModeON ? kontroler : kontroler_lokalny;
        return c.get_gornyLimit();
    }
    std::string get_lastA() const
    {
        const ARXModel &m = isOnlineModeON ? model : model_lokalny;
        return m.get_lastA();
    }
    std::string get_lastB() const
    {
        const ARXModel &m = isOnlineModeON ? model : model_lokalny;
        return m.get_lastB();
    }
    int get_okres() const
    {
        const WartZadana &w = isOnlineModeON ? wartosc : wartosc_lokalna;
        return w.get_okres();
    }
    double get_wartoscZadana() const { return wartoscZadana; }
    bool getTrybPracyInstancji() { return trybPracyInstancji; }
    bool getIsOnlineModeON() { return isOnlineModeON; }
    PIDController *getPID() { return &kontroler; }
    ARXModel *getModel() { return &model; }
    Nadajnik *getNadajnik() { return &nadajnik; }
    Odbiornik *getOdbiornik() { return &odbiornik; }
    int getKrok() { return krok; }
    void setKrok(int kroknew) { krok = kroknew; }
    void setInterval(int intervalnew){interval=intervalnew;}
    int getInterval(){return interval;}
    bool getCzyDziala() const {
        return czyDziala;
    }
    void setDt(double dtValue){
        dt=dtValue;
    }

    void setCzyDziala(bool wartosc) {
        czyDziala = wartosc;
    }
    double getWartoscProcesu(){return wartoscProcesu;}
private:
    ARXModel model;
    PIDController kontroler;
    WartZadana wartosc;
    ARXModel model_lokalny;
    PIDController kontroler_lokalny;
    WartZadana wartosc_lokalna;
    Nadajnik nadajnik;
    Odbiornik odbiornik;
    int krok = 0;
    int interval;
    double wartoscProcesu = 0.0;
    double wartoscZadana = 0.0;
    double sygnalKontrolny = 0.0;
    double wartoscProcesuLokalna = 0.0;
    double wartoscZadanaLokalna = 0.0;
    double sygnalKontrolnyLokalny = 0.0;
    double obliczone=0.0;
    bool trybPracyInstancji=false;
    bool isOnlineModeON = false;
    bool czyDziala =false;
    double dt;
};
