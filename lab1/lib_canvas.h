#ifndef LIB_CANVAS_H
#define LIB_CANVAS_H

#include "ui_mainwindow.h"
#include "dots.h"

typedef struct canvas canvas_t;
struct canvas
{
    QGraphicsScene* scene;
    double width;
    double height;
};

int lib_canvas_clear_screen(const canvas_t& canvas);

int lib_canvas_draw_line(const canvas_t& canvas, const dot_t& dot1, const dot_t& dot2);

#endif // LIB_CANVAS_H
