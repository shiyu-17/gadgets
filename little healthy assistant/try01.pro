#-------------------------------------------------
#
# Project created by QtCreator 2022-08-17T21:06:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = try01
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        widget.cpp \
    mydialog.cpp \
    plandialog.cpp \
    addialog.cpp \
    multimedia.cpp

HEADERS += \
        widget.h \
    mydialog.h \
    plandialog.h \
    addialog.h \
    connection.h \
    multimedia.h

FORMS += \
        widget.ui \
    mydialog.ui \
    plandialog.ui \
    addialog.ui \
    multimedia.ui

QT += sql
QT += core gui multimedia multimediawidgets
QT += multimedia multimediawidgets
QT	+= charts
