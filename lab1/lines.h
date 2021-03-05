#ifndef LINES_H
#define LINES_H

#include <stdio.h>
#include <stdlib.h>

#include "lib_errors.h"
#include "dots.h"
#include "lib_canvas.h"

typedef struct line line_t;
struct line
{
    int dot_1;
    int dot_2;
};

typedef struct lines_info lines_info_t;
struct lines_info
{
    int amount;
    line_t* arr;
};

int lines_info_initialize(lines_info_t& lines_info, line_t *arr, const int &amount);

int lines_info_check_array(const lines_info_t& lines_info);

int lines_info_free_arr(const lines_info_t& lines_info);

int lines_info_input(lines_info_t& lines_info, FILE *f);

int lines_info_output(const lines_info_t& lines_info, FILE *f);

int lines_draw(const lines_info_t& lines_info, const dots_info_t &dots_info, const canvas_t& canvas);

#endif // LINES_H
