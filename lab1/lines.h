#ifndef LINES_H
#define LINES_H

#include <stdio.h>
#include <stdlib.h>

#include "lib_errors.h"
#include "dots.h"
#include "lib_canvas.h"

struct line_t
{
    int dot_1;
    int dot_2;
};

struct lines_info_t
{
    int amount;
    line_t* arr;
};

int lines_info_initialize(lines_info_t& lines_info, line_t* const arr, const int &amount);

int lines_info_check_array(const lines_info_t& lines_info);

int lines_info_free_arr(lines_info_t& lines_info);

int lines_info_input(lines_info_t& lines_info, FILE *f);

int lines_info_output(FILE *f, const lines_info_t& lines_info);

int lines_draw(const lines_info_t& lines_info, const dots_info_t &dots_info, const canvas_t& canvas);

#endif // LINES_H
