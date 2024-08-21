#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "loginauth.h"
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    QString getEmail();
    QString getPassword();
    QString getToken();

    ~Login();
signals:
    void goBack();
    void home(bool );
public slots:
    void handleSuccess(QString& token);

private slots:
    void on_backButton_clicked();

    void on_loginButton_clicked();

    void on_signUpButton_clicked();

    void checkLogin();


private:
    Ui::Login *ui;
    LoginAuth loginHandler;
    QString idToken;
    QString email;
    bool signedUp;
    QString password;
};

#endif // LOGIN_H
