#include "lib_canvas.h"

int lib_canvas_clear_screen(const scene_type &scene)
{
    scene->clear();

    return OK;
}

int lib_canvas_draw_line(const canvas_t& canvas, const dot_t& dot1, const dot_t& dot2)
{
    canvas.scene->addLine(
        dot1.x + canvas.width / 2,
        dot1.y + canvas.height / 2,
        dot2.x + canvas.width / 2,
        dot2.y + canvas.height / 2);

    return OK;
}
