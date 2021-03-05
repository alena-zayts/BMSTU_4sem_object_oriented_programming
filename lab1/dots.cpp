#include "dots.h"

int dots_info_initialize(dots_info_t& dots_info, dot_t *arr, const int amount)
{
    dots_info.arr = arr;
    dots_info.amount = amount;

    return OK;
}

int dots_info_check_array(const dots_info_t& dots_info)
{
    if (!dots_info.arr)
    {
        return ERR_NO_FIGURE;
    }

    return OK;
}

int dots_info_free_arr(dots_info_t& dots_info)
{
    free(dots_info.arr);

    return OK;
}

int dots_info_read_amount(dots_info_t& dots_info, FILE* f)
{
    if (fscanf(f, "%d", &(dots_info.amount)) != 1)
    {
        return ERR_INPUT;
    }

    if (dots_info.amount < 2)
    {
        return ERR_DOTS_AMOUNT;
    }

    return OK;
}

int dots_info_allocate_arr(dots_info_t& dots_info)
{
    dot_t* arr_tmp = (dot_t*) malloc(dots_info.amount * sizeof(dot_t));

    if (!arr_tmp)
    {
        return ERR_MEM;
    }

    dots_info.arr = arr_tmp;

    return OK;
}

int dots_arr_read(dot_t *dots_arr, const int& amount, FILE* f)
{
    if (!dots_arr)
    {
        return ERR_NO_FIGURE;
    }

    int rc = OK;
    for (int i = 0; (i < amount) && (rc == OK); i++)
    {
        if ((fscanf(f, "%lf %lf %lf", &dots_arr[i].x,
                    &dots_arr[i].y, &dots_arr[i].z)) != 3)
        {
            rc = ERR_INPUT;
        }
    }

    return rc;
}

int dots_info_input(dots_info_t& dots_info, FILE* f)
{
    int rc = dots_info_read_amount(dots_info, f);
    if (rc != OK)
    {
        return rc;
    }

    rc = dots_info_allocate_arr(dots_info);
    if (rc != OK)
    {
        return rc;
    }

    rc = dots_arr_read(dots_info.arr, dots_info.amount, f);
    if (rc != OK)
    {
        dots_info_free_arr(dots_info);
    }

    return rc;
}

int dots_arr_output(const dot_t* dots_arr, const int& amount, FILE* f)
{
    if (!dots_arr)
    {
        return ERR_NO_FIGURE;
    }

    fprintf(f, "%d\n", amount);
    for (int i = 0; i < amount; i++)
    {
        fprintf(f, "%lf %lf %lf\n", dots_arr[i].x, dots_arr[i].y, dots_arr[i].z);
    }

    return OK;
}

int dots_info_output(const dots_info_t& dots_info, FILE* f)
{
    int rc = dots_arr_output(dots_info.arr, dots_info.amount, f);

    return rc;
}

int dots_arr_find_centre_x(dot_t& centre, const dot_t *dots_arr, const int amount)
{
    if (!dots_arr)
    {
        return ERR_NO_FIGURE;
    }

    double min = dots_arr[0].x, max = dots_arr[0].x;
    for (int i = 0; i < amount; i++)
    {
        if (dots_arr[i].x < min)
        {
            min = dots_arr[i].x;
        }
        if (dots_arr[i].x > max)
        {
            max = dots_arr[i].x;
        }
    }
    centre.x = (max + min) / 2;

    return OK;
}
int dots_arr_find_centre_y(dot_t& centre, const dot_t *dots_arr, const int amount)
{
    if (!dots_arr)
    {
        return ERR_NO_FIGURE;
    }

    double min = dots_arr[0].y, max = dots_arr[0].y;
    for (int i = 0; i < amount; i++)
    {
        if (dots_arr[i].y < min)
        {
            min = dots_arr[i].y;
        }
        if (dots_arr[i].y > max)
        {
            max = dots_arr[i].y;
        }
    }
    centre.y = (max + min) / 2;

    return OK;
}

int dots_arr_find_centre_z(dot_t& centre, const dot_t *dots_arr, const int amount)
{
    if (!dots_arr)
    {
        return ERR_NO_FIGURE;
    }

    double min = dots_arr[0].z, max = dots_arr[0].z;
    for (int i = 0; i < amount; i++)
    {
        if (dots_arr[i].z < min)
        {
            min = dots_arr[i].z;
        }
        if (dots_arr[i].z > max)
        {
            max = dots_arr[i].z;
        }
    }

    centre.z = (max + min) / 2;

    return OK;
}

int dots_arr_find_centre(dot_t& centre, const dot_t *dots_arr, const int amount)
{
    if (!dots_arr)
    {
        return ERR_NO_FIGURE;
    }

    int rc = dots_arr_find_centre_x(centre, dots_arr, amount);
    if (rc != OK)
    {
        return rc;
    }

    rc = dots_arr_find_centre_y(centre, dots_arr, amount);
    if (rc != OK)
    {
        return rc;
    }

    rc = dots_arr_find_centre_z(centre, dots_arr, amount);

    return OK;
}

int dot_shift(dot_t& dot, const shift_params_t& shifts)
{
    dot.x += shifts.dx;
    dot.y += shifts.dy;
    dot.z += shifts.dz;

    return OK;
}

int dots_info_shift(dots_info_t& dots_info, const shift_params_t& shifts)
{
    if (!dots_info.arr)
    {
        return ERR_NO_FIGURE;
    }

    int rc = OK;
    for (int i = 0; (i < dots_info.amount) && (rc == OK); i++)
    {
        rc = dot_shift(dots_info.arr[i], shifts);
    }

    return rc;
}

int dot_scale(dot_t& dot, const scale_params_t& coeffs, const dot_t& scale_centre)
{
    dot.x = coeffs.kx * dot.x + scale_centre.x * (1 - coeffs.kx);
    dot.y = coeffs.ky * dot.y + scale_centre.y * (1 - coeffs.ky);
    dot.z = coeffs.kz * dot.z + scale_centre.z * (1 - coeffs.kz);

    return OK;
}

int dots_info_scale(dots_info_t& dots_info, const scale_params_t& coeffs, const dot_t& scale_centre)
{
    if (!dots_info.arr)
    {
        return ERR_NO_FIGURE;
    }

    int rc = OK;
    for (int i = 0; (i < dots_info.amount) && (rc == OK); i++)
    {
        rc = dot_scale(dots_info.arr[i], coeffs, scale_centre);
    }

    return rc;
}

int to_radians(turn_params_t& angles)
{
    angles.teta_x *= (PI / 180);
    angles.teta_y *= (PI / 180);
    angles.teta_z *= (PI / 180);

    return OK;
}

int dot_turn(dot_t& dot, turn_params_t angles, const dot_t& turn_centre)
{
    int rc = to_radians(angles);
    if (rc != OK)
    {
        return rc;
    }

    double cos_teta, sin_teta;
    double tmp;

    //вокруг ox
    cos_teta = cos(angles.teta_x);
    sin_teta = sin(angles.teta_x);
    tmp = dot.y;

    dot.y = (turn_centre.y +
             (dot.y - turn_centre.y) * cos_teta +
             (dot.z - turn_centre.z) * sin_teta);
    dot.z = (turn_centre.z -
             (tmp - turn_centre.y) * sin_teta +
             (dot.z - turn_centre.z) * cos_teta);

    //вокруг oy
    cos_teta = cos(angles.teta_y);
    sin_teta = sin(angles.teta_y);
    tmp = dot.x;

    dot.x = (turn_centre.x +
             (dot.x - turn_centre.x) * cos_teta +
             (dot.z - turn_centre.z) * sin_teta);
    dot.z = (turn_centre.z -
             (tmp - turn_centre.x) * sin_teta +
             (dot.z - turn_centre.z) * cos_teta);

    //вокруг oz
    cos_teta = cos(angles.teta_z);
    sin_teta = sin(angles.teta_z);
    tmp = dot.x;

    dot.x = (turn_centre.x +
             (dot.x - turn_centre.x) * cos_teta +
             (dot.y - turn_centre.y) * sin_teta);
    dot.y = (turn_centre.y -
             (tmp - turn_centre.x) * sin_teta +
             (dot.y - turn_centre.y) * cos_teta);
    return OK;
}

int dots_info_turn(dots_info_t& dots_info, const turn_params_t& angles, const dot_t& turn_centre)
{
    if (!dots_info.arr)
    {
        return ERR_NO_FIGURE;
    }

    int rc = OK;
    for (int i = 0; (i < dots_info.amount) && (rc == OK); i++)
    {
        rc = dot_turn(dots_info.arr[i], angles, turn_centre);
    }

    return rc;
}
