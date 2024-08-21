#include "calender.h"
#include "ui_calender.h"
#include <QPixmap>

Calender::Calender(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calender)
{
    ui->setupUi(this);
    QPixmap pixMap(":/Weather.png");
    ui->pic->setPixmap(pixMap);
    ui->pic->setScaledContents(true);
    ui->pic->setFixedSize(ui->pic->pixmap().size());
}

Calender::~Calender()
{
    delete ui;
}

void Calender::on_calendarWidget_clicked(const QDate &date)
{
//    popup = new PopUp(this);
//    popup->show();
}


void Calender::on_backButton_clicked()
{
    hide();
    if(clicked)
    {
        parent = this->parentWidget()->parentWidget();
    }
    else
    {
        parent = this->parentWidget();
    }
    parent->show();
}

