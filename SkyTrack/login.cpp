#include "login.h"
#include "ui_login.h"
#include "loginauth.h"
#include <QPixmap>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    QPixmap pixMap(":/Weather.png");
    ui->loginLabel->setPixmap(pixMap);
    ui->loginLabel->setScaledContents(true);
    ui->loginLabel->setFixedSize(ui->loginLabel->pixmap().size());
    loginHandler.setAPIKey("");
    ui->lineEdit->setPlaceholderText("Ex. user09@gmail.com");
    ui->lineEdit_2->setPlaceholderText("Ex. CS10023 - minimum size of 6 letters");
    connect(&loginHandler, &LoginAuth::userSignedIn, this, &Login::handleSuccess);
    connect(this, &Login::goBack, this, &Login::checkLogin);

}

QString Login::getEmail()
{
    return email;
}

QString Login::getPassword()
{
    return password;
}

QString Login::getToken()
{
    return idToken;
}

Login::~Login()
{
    delete ui;
}

void Login::handleSuccess(QString &token)
{
    idToken = token;
    emit goBack();
}

void Login::on_backButton_clicked()
{
    hide();
    QWidget *parent = this->parentWidget();
    parent->show();
    emit home(signedUp);
}


void Login::on_loginButton_clicked()
{
    QString name = ui->lineEdit->text();
    QString pass = ui->lineEdit_2->text();
    email = name;
    password = pass;
    loginHandler.signUserin(name, pass);
}

void Login::checkLogin()
{
    if(idToken != "")
    {
        if(signedUp)
        {
            ui->stateMessage->setText("signed up successfully!");
            ui->stateMessage->setStyleSheet("color: #028A0F");
        }
        else
        {
            ui->stateMessage->setText("signed in successfully!");
            ui->stateMessage->setStyleSheet("color: #028A0F");
        }

    }
    else
    {
        if(signedUp)
        {
            ui->stateMessage->setText("Invalid password length or email. Please try again!");
            ui->stateMessage->setStyleSheet("color: #B90E0A");
            signedUp = false;
        }
        else
        {
            ui->stateMessage->setText("Invalid login. Please try again or sign up!");
            ui->stateMessage->setStyleSheet("color: #B90E0A");
            signedUp = false;
        }

    }
}

void Login::on_signUpButton_clicked()
{
    QString name = ui->lineEdit->text();
    QString pass = ui->lineEdit_2->text();
    email = name;
    password = pass;
    signedUp = true;
    loginHandler.signUserup(name, pass);
}
