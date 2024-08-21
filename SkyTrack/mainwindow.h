#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "QtWidgets/qcombobox.h"
#include "QtWidgets/qlabel.h"
#include "login.h"
#include "converter.h"
#include "todolist.h"
#include "api_request.h"
#include "calender.h"


QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void checkHour(QTime);
    ~MainWindow();
    void getQuote();
    void parseJson(QByteArray& byteArray);
    void displayQuote(QString& );
public slots:
    void connectToBase(bool);

private slots:

    void on_btnPage_clicked();

    void on_btnPage_4_clicked();

    void on_btnPage_5_clicked();

    void displayTime();

    void updateData();

    void displayWeather();

    void on_btnPage_6_clicked();


    void on_btnPage_3_clicked();

    void networkReplyReadyRead();

    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Login *login;
    Converter *convert;
    ToDoList *list;
    DataBase* db;
    API_REQUEST *req;
    Calender *cal;
    QComboBox *cityComboBox;
    QLabel *weatherLabel;
    QNetworkAccessManager* mNetAccessManager;
    QNetworkReply *networkReply;
    bool connected;

    void UI();


};
#endif // MAINWINDOW_H
