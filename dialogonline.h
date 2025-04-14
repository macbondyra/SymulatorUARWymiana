#ifndef DIALOGONLINE_H
#define DIALOGONLINE_H

#include <QDialog>


namespace Ui {
class DialogOnline;
}

class DialogOnline : public QDialog
{
    Q_OBJECT

public:
    explicit DialogOnline(QWidget *parent = nullptr);
    ~DialogOnline();

private:
    Ui::DialogOnline *ui;

};

#endif // DIALOGONLINE_H
