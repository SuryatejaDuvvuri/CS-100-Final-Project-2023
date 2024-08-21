#include "api_request.h"
#include "QtCore/qjsonarray.h"
#include "QtCore/qjsondocument.h"
#include "QtCore/qjsonobject.h"
#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
API_REQUEST::API_REQUEST(QObject *parent): QObject{parent}
{
    location = "Riverside";
}

void API_REQUEST::sendRequest(){
    QEventLoop eventLoop;

    QNetworkAccessManager manager;
    QObject :: connect(&manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    //http request
    QNetworkRequest req(QUrl(QString("https://api.openweathermap.org/data/2.5/weather?q=Riverside&appid=585a83c5902a2ee0bb158959837e94d0&units=imperial")));
    reply = manager.get(req);
    eventLoop.exec();

//     when data is able to be exctracted
    if (reply -> error() == QNetworkReply :: NoError){
        qDebug() << "Able to extract data" << reply -> readAll();
        delete reply;
    }
    //when data fails to extract
    else {
        qDebug() << "Failure to retrieve data" << reply -> errorString();
        delete reply;
    }
}

void API_REQUEST::get(QString destination)
{
    if(destination.length() != 0 || destination != "")
    {
       location = destination;
    }

    qInfo() << "Getting data from server....";
    reply = manager.get(QNetworkRequest(QUrl(QString("https://api.openweathermap.org/data/2.5/weather?q=" + location + "&appid=585a83c5902a2ee0bb158959837e94d0&units=imperial"))));
    connect(reply, &QNetworkReply :: readyRead, this, &API_REQUEST :: readyRead);
}

// when new data is available to read
void API_REQUEST::readyRead()
{
    QByteArray response = reply->readAll();
    parseResponse(response);
}

void API_REQUEST::parseResponse(QByteArray &response)
{
    QJsonDocument jsonDocument = QJsonDocument::fromJson(response);
    if(jsonDocument.object().contains("error"))
    {
        qDebug() << "Error Occurred!" << response;
    }
    else if (jsonDocument.object().contains("weather"))
    {

        QJsonObject weather = jsonDocument.object();
        temperature = weather.value("main").toObject().value("temp").toDouble(); // temperature
        maxTemp = weather.value("main").toObject().value("temp_max").toDouble(); // temp max
        minTemp = weather.value("main").toObject().value("temp_min").toDouble(); // temp min
        description = weather.value("weather").toArray().at(0).toObject().value("description").toString(); // description
        emit transfer();
    }
    else
    {
        qDebug() << "The response is: " << response;
    }
}

double API_REQUEST::getMinTemp()
{
    return minTemp;
}

double API_REQUEST::getMaxTemp()
{
    return maxTemp;
}

double API_REQUEST::getTemp()
{
    return temperature;
}

QString API_REQUEST::getDescription()
{
    return description;
}

QString API_REQUEST::getLocation()
{
    return location;
}


void API_REQUEST::finished(QNetworkReply *reply)
{
    Q_UNUSED(reply);
    qInfo() << "finished";
}

