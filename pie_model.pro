#-------------------------------------------------
#
# Project created by QtCreator 2017-09-08T09:24:12
#
#-------------------------------------------------

QT       += core gui sql xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pie_model
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
        pieview.cpp

HEADERS  += widget.h \
            pieview.h \
            connection.h
