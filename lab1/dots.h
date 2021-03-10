#ifndef DOTS_H
#define DOTS_H

#define _USE_MATH_DEFINES
#include <cmath>

#include <stdlib.h>
#include <stdio.h>

#include "lib_errors.h"

struct dot_t
{
    double x;
    double y;
    double z;
};

struct dots_info_t
{
    int amount;
    dot_t* arr;
};

struct shift_params_t
{
    double dx;
    double dy;
    double dz;
};

struct scale_params_t
{
    double kx;
    double ky;
    double kz;
};

struct turn_params_t
{
    double teta_x;
    double teta_y;
    double teta_z;
};

int dots_info_initialize(dots_info_t& dots_info, dot_t* const arr, const int amount);

int dots_info_check_array(const dots_info_t& dots_info);

int dots_info_free_arr(dots_info_t& dots_info);

int dots_info_input(dots_info_t& dots_info, FILE *f);

int dots_info_output(FILE *f, const dots_info_t& dots_info);

int dots_arr_find_centre(dot_t& centre, const dot_t *dots_arr, const int &amount);

int dot_shift(dot_t& dot, const shift_params_t& shifts);

int dots_info_shift(dots_info_t& dots_info, const shift_params_t& shifts);

int dot_scale(dot_t& dot, const scale_params_t& coeffs, const dot_t &scale_centre);

int dots_info_scale(dots_info_t& dots_info, const scale_params_t& coeffs, const dot_t& scale_centre);

int dot_turn(dot_t& dot, turn_params_t angles, const dot_t &turn_centre);

int dots_info_turn(dots_info_t& dots_info, const turn_params_t& angles, const dot_t& turn_centre);

#endif // DOTS_H
