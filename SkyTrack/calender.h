#ifndef CALENDER_H
#define CALENDER_H
#include "popup.h"
#include <QDialog>


namespace Ui {
class Calender;
}

class Calender : public QDialog
{
    Q_OBJECT

public:
    explicit Calender(QWidget *parent = nullptr);
    ~Calender();

private slots:
    void on_calendarWidget_clicked(const QDate &date);

    void on_backButton_clicked();

private:
    Ui::Calender *ui;
    PopUp *popup;
    QWidget *parent;
    bool clicked;
};

#endif // CALENDER_H
