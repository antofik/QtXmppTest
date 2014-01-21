#-------------------------------------------------
#
# Project created by QtCreator 2014-01-17T15:44:11
#
#-------------------------------------------------

QT       += core gui webkit webkitwidgets
CONFIG += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DesktopClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mainmenu.cpp \
    visitorlistview.cpp \
    core.cpp \
    visitorhelper.cpp \
    visitor.cpp \
    connectionhelper.cpp \
    visitorupdater.cpp \
    visitorchat.cpp

HEADERS  += mainwindow.h \
    mainmenu.h \
    visitorlistview.h \
    core.h \
    visitorhelper.h \
    visitor.h \
    connectionhelper.h \
    visitorupdater.h \
    visitorchat.h

FORMS    += mainwindow.ui \
    mainmenu.ui \
    visitorlistview.ui \
    visitorchat.ui


include(X:\Libraries\qxmpp-0.7.6\qxmpp.pri)
INCLUDEPATH += $$QXMPP_INCLUDEPATH
LIBS += -L../src $$QXMPP_LIBS
LIBS += -LX:\Libraries
