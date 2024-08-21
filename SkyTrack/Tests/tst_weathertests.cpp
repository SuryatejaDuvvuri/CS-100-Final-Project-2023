#include <QtTest>
#include <QCoreApplication>

// add necessary includes here
#include <QDialog>
#include "../loginauth.h"
//#include "tst_weathertests.moc"

class WeatherTests : public QObject
{
    Q_OBJECT

public:
    WeatherTests();
    ~WeatherTests();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

WeatherTests::WeatherTests()
{

}

WeatherTests::~WeatherTests()
{

}

void WeatherTests::initTestCase()
{

}

void WeatherTests::cleanupTestCase()
{

}

void WeatherTests::test_case1()
{
    LoginAuth *authHandler = new LoginAuth(this);
    authHandler->signUserup("RandyG66@gmail.com", "CS10023");
}

QTEST_MAIN(WeatherTests)

