#ifndef DIALOGTESTONLINE_H
#define DIALOGTESTONLINE_H

#include <QDialog>

namespace Ui {
class dialogTestOnline;
}

class dialogTestOnline : public QDialog
{
    Q_OBJECT

public:
    explicit dialogTestOnline(QWidget *parent = nullptr);
    ~dialogTestOnline();
    bool tryb;
    bool getTryb();

private:
    Ui::dialogTestOnline *ui;
};

#endif // DIALOGTESTONLINE_H
