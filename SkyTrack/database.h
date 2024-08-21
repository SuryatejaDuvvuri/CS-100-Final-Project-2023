#ifndef DATABASE_H
#define DATABASE_H

#include "QtCore/qjsonarray.h"
#include "api_request.h"
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = nullptr);
    void callDataBase(const QString&,const QString&,const QString&,bool);
    void addList(const QString& );
    void removeTask(const QString& );
    void clearTasks();
    void logOut();
    void addUser(const QString&, const QString&, const QString& );
    void parseResponse(const QByteArray &response);
    QString getUID();
    ~DataBase();


public slots:
    void networkReplyReadyRead();
    void collectData(QJsonObject& );
    QJsonArray getTasks();

signals:
    void accessGranted(QJsonObject& );
    void addTask(QString& );
    void accessTasks();

private:
    QNetworkAccessManager *networkManager;
    QNetworkReply *networkReply;
    QString email;
    QString id_token;
    QStringList taskKeys;
    QString uid;
    QJsonArray tasksArr;
    API_REQUEST *data;

};

#endif // DATABASE_H
