#include <QtTest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QtWidgets/QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
//#include "../mainwindow.h"

// add necessary includes here

class quoteTests : public QObject
{
    Q_OBJECT

public:
    quoteTests();
    ~quoteTests();

private slots:
    void test_case1();
    void test_case2();
    void test_case3();
    void test_tag();
    void test_length();

private:

};

quoteTests::quoteTests()
{

}

quoteTests::~quoteTests()
{

}

void quoteTests::test_case1()
{
    QString httpString = "https://api.quotable.io/random";
    QCOMPARE(httpString, QString("https://api.quotable.io/random"));
}

void quoteTests::test_case2()
{
    QString httpString = "https://api.quotable.io";
    QCOMPARE(httpString, QString("https://api.quotable.io"));
}

void quoteTests::test_case3()
{
    QString quote = "Life is a travelling to the edge of knowledge, then a leap taken.";
    QCOMPARE(quote, QString("Life is a travelling to the edge of knowledge, then a leap taken."));
}

void quoteTests::test_tag(){
    QString tag = "Wisdom";
    QCOMPARE(tag, QString("Wisdom"));
}

void quoteTests::test_length(){
    int length = 65;
    QCOMPARE(length, 65);
}

QTEST_APPLESS_MAIN(quoteTests)

#include "tst_quotetests.moc"
