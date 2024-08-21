#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "converter.h"
#include <QDebug>
#include <QPixmap>
#include <QTimer>
#include <QDate>
#include <QtWidgets/QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = new DataBase(this);
    login = new Login(this);
    req = new API_REQUEST(this);
    QTimer *timer = new QTimer(this);
    QTimer *data = new QTimer(this);

    UI();
    connect(timer, SIGNAL(timeout()), this, SLOT(displayTime()));
    connect(data, SIGNAL(timeout()), this,  SLOT(updateData()));
    data->setInterval(360000000);
    timer->start();
    data->start();
    QDate date = QDate::currentDate();
    QString dateText = date.toString("ddd MMMM d yyyy");
    ui->showDate->setText(dateText);
    QPixmap pixMap(":/Weather.png");
    ui->label_pic->setPixmap(pixMap);
    ui->label_pic->setScaledContents(true);
    ui->label_pic->setFixedSize(ui->label_pic->pixmap().size());
    req->sendRequest();
    connect(req, &API_REQUEST::transfer, this, &MainWindow::displayWeather);
    mNetAccessManager = new QNetworkAccessManager(this);
    connect(login, &Login::home, this, &MainWindow::connectToBase);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectToBase(bool isSignedUp)
{
    db->callDataBase(login->getEmail(),login->getPassword(), login->getToken(), isSignedUp);
    getQuote();
    req->get(ui->comboBox->currentText());
    connected = true;
}
void MainWindow::on_btnPage_clicked()
{
    hide();
    login->show();
}

void MainWindow::on_btnPage_4_clicked()
{
    hide();
    convert = new Converter(this);
    convert->show();
}

void MainWindow::on_btnPage_5_clicked()
{
    close();
    exit(0);
}

void MainWindow::checkHour(QTime timeObj)
{
    if(timeObj.hour() < 12)
    {
        ui->msg->setText("Good Morning!");
    }
    else if (timeObj.hour() < 18)
    {
        ui->msg->setText("Good Afternoon");
    }
    else
    {
        ui->msg->setText("Good Evening!");
    }
}

void MainWindow::displayTime()
{
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss AP t");
    checkHour(time);
    ui->digitalTimer->setText(time_text);
}

void MainWindow::updateData()
{
    QTime time = QTime::currentTime();
    checkHour(time);
    req->get(req->getLocation());
}

void MainWindow::displayWeather()
{
    ui->cityName->setText(req->getLocation());
    ui->temp->setText(QString::number(req->getTemp(),'d',3) + "˚C");
    //temp min
    ui->min->setText("L: " + QString::number(req->getMinTemp(),'d',3) + "˚C");
    // temp max
    ui->max->setText("H: " + QString::number(req->getMaxTemp(),'d',3) + "˚C");
     ui->descrip->setText(req->getDescription());
}

void MainWindow::on_btnPage_6_clicked()
{
    hide();
    list = new ToDoList(this, login);
    list->show();
}

void MainWindow::on_btnPage_3_clicked()
{
    hide();
    cal = new Calender(this);
    cal->show();
}

void MainWindow::getQuote()
{
    QUrl url("https://api.quotable.io/random");
    networkReply = mNetAccessManager->get(QNetworkRequest(url));
    connect(networkReply, &QNetworkReply::readyRead, this, &MainWindow::networkReplyReadyRead);
}

void MainWindow::networkReplyReadyRead()
{
    QByteArray response = networkReply->readAll();
    networkReply->deleteLater();
    parseJson(response);
}

void MainWindow::parseJson(QByteArray& byteArray)
{
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(byteArray, &err);
    if(err.error!=QJsonParseError::NoError){
        return;
    }
    else if(doc.isObject())
    {
        if(doc.object().value("content").toString().length() < ui->quoteBar->maximumWidth())
        {
            QJsonObject rootObj = doc.object();
            QString val = rootObj.value("content").toString();
            displayQuote(val);
        }
        else
        {
             getQuote();
        }
    }
}
void MainWindow::displayQuote(QString& newQuote)
{
    qDebug() << newQuote;
    ui->quoteBar->setText(newQuote);
}

void MainWindow::UI()
{
    ui->comboBox -> addItem("Los Angeles");
    ui->comboBox -> addItem("San Francisco");
    ui->comboBox -> addItem("San Diego");
    ui->comboBox -> addItem("Sacramento");
    ui->comboBox -> addItem("Riverside");
    ui->comboBox -> addItem("Temecula");
    ui->comboBox -> addItem("Oceanside");
}



void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(connected)
    {
        req->get(ui->comboBox->currentText());
    }

}

