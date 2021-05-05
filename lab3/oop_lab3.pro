QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    builder.cpp \
    canvas_qt.cpp \
    carcass.cpp \
    commands.cpp \
    controller.cpp \
    director_model.cpp \
    drawer_qt.cpp \
    facade.cpp \
    factory_qt.cpp \
    link.cpp \
    loader_model.cpp \
    loader_source_file.cpp \
    main.cpp \
    mainwindow.cpp \
    manager_camera.cpp \
    manager_draw.cpp \
    manager_sccene.cpp \
    manager_transform.cpp \
    matrix_transform.cpp \
    object_camera.cpp \
    object_composite.cpp \
    object_invisible.cpp \
    object_model.cpp \
    object_visible.cpp \
    scene.cpp

HEADERS += \
    builder.hpp \
    builder_base.hpp \
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
    loader_base.hpp \
    loader_model.hpp \
    loader_source_base.hpp \
    loader_source_file.hpp \
    mainwindow.h \
    mainwindow.hpp \
    manager_base.hpp \
    manager_camera.hpp \
    manager_draw.hpp \
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
    vector.hpp \
    vector_base.hpp \
    visitor.hpp

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    config.cfg \
    cube.txt \
    octahedron.txt
