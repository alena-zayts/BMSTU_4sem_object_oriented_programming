QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    builder_model.cpp \
    canvas_qt.cpp \
    carcass.cpp \
    commands.cpp \
    controller.cpp \
    director_model.cpp \
    drawer_qt.cpp \
    facade.cpp \
    factory_qt.cpp \
    link.cpp \
    load_controller_model.cpp \
    main.cpp \
    mainwindow.cpp \
    manager_draw.cpp \
    manager_load.cpp \
    manager_sccene.cpp \
    manager_transform.cpp \
    matrix_transform.cpp \
    object_camera.cpp \
    object_composite.cpp \
    object_invisible.cpp \
    object_model.cpp \
    object_visible.cpp \
    scene.cpp \
    source_loader_file.cpp

HEADERS += \
    builder_model.hpp \
    builder_model_base.hpp \
    canvas_base.hpp \
    canvas_qt.hpp \
    carcass.hpp \
    command_base.hpp \
    commands.hpp \
    controller.hpp \
    director_model.hpp \
    drawer_base.hpp \
    drawer_qt.hpp \
    error_base.hpp \
    error_container.hpp \
    error_drawer.hpp \
    error_loader.hpp \
    error_new.hpp \
    error_scene.hpp \
    facade.hpp \
    factory_abstract.hpp \
    factory_qt.hpp \
    iterator_base.hpp \
    iterator_const.hpp \
    iterator_usual.hpp \
    iterator_vector.hpp \
    link.hpp \
    load_controller_base.hpp \
    load_controller_model.hpp \
    mainwindow.h \
    mainwindow.hpp \
    manager_base.hpp \
    manager_draw.hpp \
    manager_load.hpp \
    manager_scene.hpp \
    manager_transform.hpp \
    matrix.hpp \
    matrix_base.hpp \
    matrix_transform.hpp \
    object_camera.hpp \
    object_composite.hpp \
    object_invisible.hpp \
    object_model.hpp \
    object_scene.hpp \
    object_visible.hpp \
    point.hpp \
    points_pair.hpp \
    scene.hpp \
    source_loader_base.hpp \
    source_loader_file.hpp \
    vector.hpp \
    vector_base.hpp \
    visitor.hpp

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
