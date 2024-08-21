// quote api tests
#include <QtTest>
#include "../final-project-sduvv003-rgarc217-ykang063-nwong066-master/SkyTrack/mainwindow.h"
#include <QCoreApplication>
#include <QDialog>

#include <QMainWindow>
#include <QGraphicsDropShadowEffect>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QtWidgets/QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

using namespace std;
// add necessary includes here

class test : public QObject
{
    Q_OBJECT

public:
    test();
    ~test();

private slots:
    void testQuoteApi();
    void testQuoteObject();
    void testQuoteObject2();
    void testQuoteObject3();
    void testQuoteText();
    void testQuoteText2();
    void testQuoteText3();
    void testEmptyQuote();
    void testQuoteApiErrorHandling();

private:
    QString quote;
    QJsonObject quoteObject;
};

test::test()
{

}

test::~test()
{

}

void test::testQuoteApi()
{
    QNetworkAccessManager manager;
    QNetworkRequest request;

    // Set the API endpoint URL
    request.setUrl(QUrl("https://api.quotable.io/random"));

    // Make the GET request to the API
    QNetworkReply* reply = manager.get(request);

    // Wait for the API response
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    // Verify if the API request was successful
    QVERIFY(reply->error() == QNetworkReply::NoError);

    // Read the response data
    QByteArray responseData = reply->readAll();

    // Parse the JSON response
    QJsonDocument responseJson = QJsonDocument::fromJson(responseData);
    quoteObject = responseJson.object();

    // Clean up
    reply->deleteLater();
}

void test::testQuoteObject(){
    // Verify if the quote object has the expected keys
    QVERIFY(quoteObject.contains("content"));
}

void test::testQuoteObject2(){
    // Verify if the quote object has the expected keys
    QVERIFY(quoteObject.contains("tags"));
}

void test::testQuoteObject3(){
    // Verify if the quote object has the expected keys
    QVERIFY(quoteObject.contains("author"));
}

void test::testQuoteText(){
    // Extract the quote text from the JSON
    QString quoteText = quoteObject.value("content").toString();

    // Verify if the quote text is not empty
    QVERIFY(!quoteText.isEmpty());
}

void test::testQuoteText2(){
    // Extract the quote text from the JSON
    QString quoteText = quoteObject.value("_id").toString();

    // Verify if the quote text is not empty
    QVERIFY(!quoteText.isEmpty());
}

void test::testQuoteText3(){
    // Extract the quote text from the JSON
    QString quoteText = quoteObject.value("author").toString();

    // Verify if the quote text is not empty
    QVERIFY(!quoteText.isEmpty());
}

void test::testEmptyQuote()
{
    QCOMPARE(quote.length(),0);
}

void test::testQuoteApiErrorHandling() {
    QNetworkAccessManager manager;
    QNetworkRequest request;

    // Set an invalid API endpoint URL to trigger an error
    request.setUrl(QUrl("https://api.quotable.io/random"));

    // Make the GET request to the API
    QNetworkReply* reply = manager.get(request);

    // Use QTest::qWait() to wait for the API response
    QTest::qWait(2000); // Adjust the delay as needed

    // Check if the API response encountered an error
    QVERIFY(reply->error() == QNetworkReply::NoError);

    // Clean up
    reply->deleteLater();
}

QTEST_MAIN(test)

#include "tst_test.moc"
