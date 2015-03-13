#-------------------------------------------------
#
# Project created by QtCreator 2015-02-25T19:10:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Scouting
TEMPLATE = app


SOURCES +=    main.cpp \
	mainwindow.cpp \
    chooselocation.cpp \
       filehandler.cpp

HEADERS  += filehandler.h \
	     namespaces.h \
		   main.h \
	 chooselocation.h \
	     mainwindow.h

FORMS    += mainwindow.ui \
	chooselocation.ui

# INCLUDEPATH += "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\include"

CONFIG += c++11

DISTFILES +=
