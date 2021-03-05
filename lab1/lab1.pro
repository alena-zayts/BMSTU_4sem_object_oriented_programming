QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    commands.cpp \
    dots.cpp \
    lib_canvas.cpp \
    lib_errors.cpp \
    lines.cpp \
    main.cpp \
    mainwindow.cpp \
    model.cpp

HEADERS += \
    commands.h \
    dots.h \
    lib_canvas.h \
    lib_errors.h \
    lines.h \
    mainwindow.h \
    model.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    in_cube.txt \
    in_line.txt \
    in_sphere.txt \
    out.txt
