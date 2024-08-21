#ifndef LOGINAUTH_H
#define LOGINAUTH_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include "database.h"

class LoginAuth : public QObject
{
    Q_OBJECT
public:
    explicit LoginAuth(QObject *parent = nullptr);
    ~LoginAuth();
    void setAPIKey(const QString & newKey);
    void signUserup(const QString &username, const QString &password);
    void signUserin(const QString &username, const QString &password);
    void performPOST(const QString &url, const QJsonDocument & payload);
    void parseResponse(const QByteArray &response);

public slots:
    void networkReplyReadyRead();


signals:
    void userSignedIn(QString& token);
private:
    QString apiKey;
    QNetworkAccessManager *networkAccessManager;
    QNetworkReply *networkReply;
    QString idToken;
    DataBase baseHandler;
    QStringList details;
    bool signedUp;
    QString userName;
    QString passWord;

};

#endif // LOGINAUTH_H
