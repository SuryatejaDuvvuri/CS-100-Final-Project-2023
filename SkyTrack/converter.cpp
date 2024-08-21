#include "converter.h"
#include "ui_converter.h"
#include <QPixmap>
#include <QDoubleSpinBox>

Converter::Converter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Converter)
{
    ui->setupUi(this);
    QPixmap pixMap(":/Weather.png");
    ui->pic->setPixmap(pixMap);
    ui->pic->setScaledContents(true);
    ui->pic->setFixedSize(ui->pic->pixmap().size());
}

Converter::~Converter()
{
    delete ui;
}

void Converter::on_pushButton_3_clicked()
{
    hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}




void Converter::on_pushButton_clicked()
{
    if(ui->spinbox->hasFocus())
    {
        double fahrenheit = ui->spinbox->value();
        double convertF = (fahrenheit - 32) * (9/5);
        QString text = "Celsius: " + QString::number(convertF,'d',3);

        ui->Res->setText(text);
    }
    else if(ui->spinbox_2->hasFocus())
    {
        double celsius = ui->spinbox->value();
        double convertF = (celsius * 9/5) + 32;

        QString text = "Fahrenheit: " + QString::number(convertF,'d',3);

        ui->Res->setText(text);
    }

}

