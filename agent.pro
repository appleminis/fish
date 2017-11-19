#-------------------------------------------------
#
# Project created by QtCreator 2015-10-23T10:38:08
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = agent
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    banc.cpp \
    poisson.cpp \
    vect.cpp \
    obstacle.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    banc.h \
    poisson.h \
    vect.h \
    obstacle.h

FORMS    += mainwindow.ui

LIBS += -lGL -lGLU
