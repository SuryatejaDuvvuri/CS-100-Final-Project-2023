QT += testlib
QT += widgets
QT += gui core network
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

ARCHS = armv7 armv7s

VALID_ARCHS = armv6 armv7 armv7s arm64

SOURCES +=  tst_test.cpp

