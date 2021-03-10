#ifndef LIB_CANVAS_H
#define LIB_CANVAS_H

#include "ui_mainwindow.h"
#include "dots.h"

//struct scene_t
//{
//    QGraphicsScene* screen;
//};

typedef QGraphicsScene* scene_type;

struct canvas_t
{
    scene_type scene;
    double width;
    double height;
};


int lib_canvas_clear_screen(const scene_type& scene);

int lib_canvas_draw_line(const canvas_t& canvas, const dot_t& dot1, const dot_t& dot2);

#endif // LIB_CANVAS_H
