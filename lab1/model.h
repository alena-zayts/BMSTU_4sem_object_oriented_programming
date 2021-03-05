#ifndef MODEL_H
#define MODEL_H

#include "ui_mainwindow.h"
#include "lib_errors.h"
#include "dots.h"
#include "lines.h"
#include "lib_canvas.h"

typedef struct model model_t;
struct model
{
    dots_info_t dots;
    lines_info_t lines;
    dot_t centre;
};

model_t& model_init(void);

int model_free(model_t &model);

int model_download(model_t& model, const char *file_name);

int model_find_centre(dot_t& centre, const dots_info_t& dots_info);

int model_upload(const model_t& model, const char *file_name);

int model_draw(const model_t& model, const canvas_t& canvas);

int model_shift(model_t& model, const shift_params_t& shifts);

int model_scale(model_t& model, const scale_params_t& coeffs);

int model_turn(model_t& model, const turn_params_t &angles);

#endif // MODEL_H
