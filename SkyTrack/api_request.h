#ifndef API_REQUEST_H
#define API_REQUEST_H

#include <QObject>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QAuthenticator>
#include <QNetworkProxy>

class API_REQUEST : public QObject
{
    Q_OBJECT
public:
    explicit API_REQUEST(QObject *parent = nullptr);

signals:

public slots:
    void get(QString location);
    void sendRequest();
    void parseResponse(QByteArray&);
    double getMinTemp();
    double getMaxTemp();
    double getTemp();
    QString getDescription();
    QString getLocation();
signals:
    void transfer();
private slots:
    void readyRead();
    void finished(QNetworkReply *reply);


private:
    QNetworkAccessManager manager;
    QNetworkReply *reply;
    double minTemp;
    double maxTemp;
    double temperature;
    QString description;
    QString location;
};

#endif // API_REQUEST_H
