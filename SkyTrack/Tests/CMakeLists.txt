cmake_minimum_required(VERSION 3.5)

project(WeatherTests LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Gui Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui Test)
find_package(Qt6 REQUIRED COMPONENTS Gui Widgets)
find_package(Qt6 REQUIRED COMPONENTS Gui Network)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(WeatherTests tst_weathertests.cpp)
add_test(NAME WeatherTests COMMAND WeatherTests)

target_link_libraries(WeatherTests PRIVATE Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Test)
target_link_libraries(WeatherTests PRIVATE Qt6::Widgets)
target_link_libraries(WeatherTests PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(WeatherTests PRIVATE Qt${QT_VERSION_MAJOR}::Network)


