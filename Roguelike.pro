#-------------------------------------------------
#
# Project created by QtCreator 2018-01-10T18:25:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Roguelike
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    roguelikemap.cpp \
    clinterface.cpp \
    guinterface.cpp \
    hero.cpp \
    enemy.cpp

HEADERS  += widget.h \
    roguelikemap.h \
    clinterface.h \
    guinterface.h \
    hero.h \
    enemy.h

FORMS    += widget.ui

RESOURCES += \
    img.qrc
