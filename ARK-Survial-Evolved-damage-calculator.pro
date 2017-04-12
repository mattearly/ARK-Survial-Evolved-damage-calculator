#-------------------------------------------------
#
# Project created by QtCreator 2016-06-02T13:23:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ARK-Survial-Evolved-damage-calculator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    defaultweapondamage.h \
    weaponurls.h \
    defaultdinodamage.h \
    dinourls.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons.qrc

win32:RC_ICONS += arkdc.ico

CONFIG += c++11
