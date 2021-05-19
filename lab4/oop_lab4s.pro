QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    elevator.cpp \
    elevator_cabin.cpp \
    elevator_controller.cpp \
    elevator_doors.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    constants.h \
    elevator.h \
    elevator_cabin.h \
    elevator_controller.h \
    elevator_doors.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    lab_04.pro \
    lab_04.pro

DISTFILES += \
    lab_04.mdj \
    oop_lab4s.pro.user
