#ifndef DOTS_H
#define DOTS_H

#define PI 3.1415926

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "lib_errors.h"

typedef struct dot dot_t;
struct dot
{
    double x;
    double y;
    double z;
};

typedef struct dots_info dots_info_t;
struct dots_info
{
    int amount;
    dot_t* arr;
};

typedef struct shift_params shift_params_t;
struct shift_params
{
    double dx;
    double dy;
    double dz;
};

typedef struct scale_params scale_params_t;
struct scale_params
{
    double kx;
    double ky;
    double kz;
};

typedef struct turn_params turn_params_t;
struct turn_params
{
    double teta_x;
    double teta_y;
    double teta_z;
};

int dots_info_initialize(dots_info_t& dots_info, dot_t *arr, const int amount);

int dots_info_check_array(const dots_info_t& dots_info);

int dots_info_free_arr(dots_info_t& dots_info);

int dots_info_input(dots_info_t& dots_info, FILE *f);

int dots_info_output(const dots_info_t& dots_info, FILE *f);

int dots_arr_find_centre(dot_t& centre, const dot_t *dots_arr, const int amount);

int dot_shift(dot_t& dot, const shift_params_t& shifts);

int dots_info_shift(dots_info_t& dots_info, const shift_params_t& shifts);

int dot_scale(dot_t& dot, const scale_params_t& coeffs, const dot_t &scale_centre);

int dots_info_scale(dots_info_t& dots_info, const scale_params_t& coeffs, const dot_t& scale_centre);

int dot_turn(dot_t& dot, turn_params_t angles, const dot_t &turn_centre);

int dots_info_turn(dots_info_t& dots_info, const turn_params_t& angles, const dot_t& turn_centre);

#endif // DOTS_H
