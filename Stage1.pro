QT += charts core gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    Comuna.cpp \
    Pedestrian.cpp \
    Simulator.cpp \
    Stage1.cpp \
    mainwindow.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Comuna.h \
    Pedestrian.h \
    Simulator.h \
    mainwindow.h

DISTFILES += \
    "/home/theuszero/QtProyects/Stage1/config.txt"

FORMS += \
    mainwindow.ui
