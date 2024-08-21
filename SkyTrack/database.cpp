#include "database.h"
#include "api_request.h"
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QDebug>
#include <QVariantMap>
#include <QJsonObject>
#include <QJsonArray>
DataBase::DataBase(QObject *parent)
    : QObject{parent}
{
    networkManager = new QNetworkAccessManager(this);
    email = "";
    data = new API_REQUEST(this);
    connect(this, &DataBase::accessGranted, this, &DataBase::collectData);
    connect(this, &DataBase::addTask, this, &DataBase::addList);
}

DataBase::~DataBase()
{
    networkManager->deleteLater();
    networkReply->deleteLater();
}

void DataBase::networkReplyReadyRead()
{
    QByteArray response = networkReply->readAll();
    qDebug() << response;
    networkReply->deleteLater();
    parseResponse(response);
}

void DataBase::collectData(QJsonObject& val)
{
    QJsonObject tasks = val.value("lists").toObject();
    taskKeys = tasks.keys();

    for (const QString& taskKey : taskKeys) {
        QJsonArray list = tasks.value(taskKey).toArray();
        QString task = list.at(0).toString();
        tasksArr.append(task);
    }
    emit accessTasks();
}


void DataBase::callDataBase(const QString& name, const QString& password, const QString& token, bool signedUp)
{
    this->email = name;
    id_token = token;
    QUrl url("https://skytrack-e2cab-default-rtdb.firebaseio.com/Users.json?auth=" + token);
    networkReply = networkManager->get( QNetworkRequest(url));
    if(signedUp)
    {
        addUser(name, password, token);
    }
     connect(networkReply, &QNetworkReply::readyRead, this, &DataBase::networkReplyReadyRead);// displays the data in json tree

}

void DataBase::addList(const QString &list)
{
    tasksArr.append(list);
    QJsonArray arr = {list};
    QJsonDocument jsonDoc(arr);
    QNetworkRequest taskRequest(QUrl("https://skytrack-e2cab-default-rtdb.firebaseio.com/Users/" + uid + "/lists.json?auth=" + id_token));
    taskRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    networkReply = networkManager->post(taskRequest, jsonDoc.toJson());
    connect(networkReply, &QNetworkReply::finished, this, &DataBase::networkReplyReadyRead);
}

void DataBase::removeTask(const QString &task)
{
    int index = 0;
    QString userKey = "";
    for (const QString& key : taskKeys)
    {
        if(tasksArr.at(index).toString() == task)
        {
            tasksArr.removeAt(index);
            userKey = key;
            break;
        }
        index++;
    }

    QNetworkRequest taskRequest(QUrl("https://skytrack-e2cab-default-rtdb.firebaseio.com/Users/" + uid + "/lists/"+ userKey + ".json?auth=" + id_token));
    taskRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    networkReply = networkManager->deleteResource(taskRequest);
    connect(networkReply, &QNetworkReply::finished, this, &DataBase::networkReplyReadyRead);
}

void DataBase::clearTasks()
{
    while(tasksArr.size())
    {
        tasksArr.pop_back();
    }

    QNetworkRequest taskRequest(QUrl("https://skytrack-e2cab-default-rtdb.firebaseio.com/Users/" + uid + "/lists.json?auth=" + id_token));
    taskRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    networkReply = networkManager->deleteResource(taskRequest);
    connect(networkReply, &QNetworkReply::finished, this, &DataBase::networkReplyReadyRead);
}

QJsonArray DataBase::getTasks()
{
    return tasksArr;
}

void DataBase::addUser(const QString& username, const QString& password, const QString& token)
{
    QVariantMap newUsers;
    newUsers["Name"] = username;
    newUsers["Password"] = password;
    newUsers["lists"] = "";
    newUsers["events"] = "";
    QJsonDocument jsonDoc = QJsonDocument::fromVariant(newUsers);


    QUrl url("https://skytrack-e2cab-default-rtdb.firebaseio.com/Users.json?auth=" + token);
    networkReply = networkManager->get( QNetworkRequest(url));
    QNetworkRequest newUserRequest(url);
    newUserRequest.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
    networkManager->post(newUserRequest, jsonDoc.toJson());
    connect(networkReply, &QNetworkReply::finished, this, &DataBase::networkReplyReadyRead);
}

void DataBase::parseResponse(const QByteArray &response)
{
    QJsonDocument jsonDocument = QJsonDocument::fromJson(response);
    bool userFound = false;
    if(!jsonDocument.isNull() && jsonDocument.isObject())
    {

        QJsonObject obj = jsonDocument.object();
        QStringList keys = obj.keys();

        for (const QString& key : keys) {
            QJsonObject val = obj.value(key).toObject();
            if (val.value("Name").toString() == email) {
                uid = key;
                userFound = true;
                break;
            }
        }

        if(userFound)
        {
            QJsonObject val = obj.value(uid).toObject();
            emit accessGranted(val);
        }

    }
    else
    {

        qDebug() << "User not found in database!";

    }
}

QString DataBase::getUID()
{
    return uid;
}

