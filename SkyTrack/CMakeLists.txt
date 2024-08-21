cmake_minimum_required(VERSION 3.5)

project(SkyTrack VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui)

find_package(
  QT NAMES Qt6 Qt5
  COMPONENTS Core Xml Widgets Network
  REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        login.cpp
        converter.cpp
        mainwindow.cpp
        mainwindow.h
        converter.h
        login.h
        mainwindow.ui
        login.ui
        converter.ui
        loginauth.cpp
        loginauth.h
        todolist.cpp
        todolist.h
        todolist.ui
        database.cpp
        database.h
        api_request.cpp
        api_request.h
        calender.h
        calender.cpp
        calender.ui
#        popup.h
#        popup.cpp
#        popup.ui
        resources.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SkyTrack
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET SkyTrack APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(SkyTrack SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(SkyTrack
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(SkyTrack PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(SkyTrack PRIVATE Qt${QT_VERSION_MAJOR}::Network)
target_link_libraries(SkyTrack PRIVATE Qt${QT_VERSION_MAJOR}::Gui)

set_target_properties(SkyTrack PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

install(TARGETS SkyTrack
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SkyTrack)
endif()
