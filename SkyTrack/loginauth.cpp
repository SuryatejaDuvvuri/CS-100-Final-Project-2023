#include "loginauth.h"
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QDebug>
#include <QVariantMap>
#include <QJsonObject>

LoginAuth::LoginAuth(QObject *parent)
    : QObject{parent}
{
    networkAccessManager = new QNetworkAccessManager(this);
}

LoginAuth::~LoginAuth()
{
    networkAccessManager->deleteLater();
}

void LoginAuth::setAPIKey(const QString &newKey)
{
    apiKey = newKey;
}

void LoginAuth::signUserup(const QString &username, const QString &password)
{
    QString signUpEndpoint = "https://identitytoolkit.googleapis.com/v1/accounts:signUp?key=" + apiKey;
    QVariantMap variantPayload;
    variantPayload["email"] = username;
    variantPayload["password"] = password;
    variantPayload["returnSecureToken"] = true;
    userName = username;
    passWord = password;

    QJsonDocument jsonPayload = QJsonDocument::fromVariant(variantPayload);
    performPOST(signUpEndpoint, jsonPayload);
}

void LoginAuth::signUserin(const QString &username, const QString &password)
{
    QString signInEndpoint = "https://identitytoolkit.googleapis.com/v1/accounts:signInWithPassword?key=" + apiKey;

    QVariantMap variantPayload;
    variantPayload["email"] = username;
    variantPayload["password"] = password;
    variantPayload["returnSecureToken"] = true;
    userName = username;
    passWord = password;

    QJsonDocument jsonPayload = QJsonDocument::fromVariant(variantPayload);
    performPOST(signInEndpoint, jsonPayload);
}


void LoginAuth::networkReplyReadyRead()
{
    QByteArray response = networkReply->readAll();
    parseResponse(response);
}

void LoginAuth::performPOST(const QString &url, const QJsonDocument &payload)
{
    QNetworkRequest newRequest((QUrl(url)));
    newRequest.setHeader(QNetworkRequest::ContentTypeHeader,  QString("applications/json") );
    networkReply = networkAccessManager->post(newRequest, payload.toJson());
    connect(networkReply, &QNetworkReply::readyRead, this, &LoginAuth::networkReplyReadyRead);
}

void LoginAuth::parseResponse(const QByteArray &response)
{
    QJsonDocument jsonDocument = QJsonDocument::fromJson(response);
    QString token = "";
    if(jsonDocument.object().contains("error"))
    {
        qDebug() << "Error Occurred!" << response;
        emit userSignedIn(token);
    }
    else if (jsonDocument.object().contains("kind"))
    {
        token = jsonDocument.object().value("idToken").toString();
        qDebug() << "User signed in successfully!";
        emit userSignedIn(token);
    }
    else
    {
        emit userSignedIn(token);
        qDebug() << "The response is: " << response;
    }
}

