#include "model.h"

int model_initialize_null(model_t& model)
{
    int rc = lines_info_initialize(model.lines, NULL, 0);
    if (rc != OK)
    {
        return rc;
    }

    rc = dots_info_initialize(model.dots, NULL, 0);
    if (rc != OK)
    {
        return rc;
    }

    model.centre = {0, 0, 0};

    return rc;
}

model_t& model_init(void)
{
    static model_t model;
    model_initialize_null(model);

    return model;
}

int model_free(model_t& model)
{
    dots_info_free_arr(model.dots);
    lines_info_free_arr(model.lines);

    return OK;
}

int model_find_centre(dot_t& centre, const dots_info_t &dots_info)
{
    int rc = dots_arr_find_centre(centre, dots_info.arr, dots_info.amount);

    return rc;
}

int model_download(model_t& model, const char *file_name)
{
    if (!file_name)
    {
        return ERR_FILE;
    }

    FILE *f = NULL;

    if ((f = fopen(file_name, "r")) == NULL)
    {
        return ERR_FILE;
    }

    model_t model_tmp = model_init();

    int rc = dots_info_input(model_tmp.dots, f);
    if (rc != OK)
    {
        fclose(f);
        return rc;
    }

    rc = lines_info_input(model_tmp.lines, f);
    if (rc != OK)
    {
        fclose(f);
        dots_info_free_arr(model_tmp.dots);
        return rc;
    }

    rc = model_find_centre(model_tmp.centre, model_tmp.dots);
    if (rc != OK)
    {
        fclose(f);
        model_free(model_tmp);
        return rc;
    }

    fclose(f);
    model_free(model);
    model = model_tmp;

    return rc;
}

int model_check_arrays(const model_t& model)
{
    int rc = dots_info_check_array(model.dots);

    if (rc != OK)
    {
        return rc;
    }

    rc = lines_info_check_array(model.lines);

    return rc;
}

int model_upload(const model_t& model, const char *file_name)
{
    if (!file_name)
    {
        return ERR_FILE;
    }

    int rc = model_check_arrays(model);
    if (rc != OK)
    {
        return rc;
    }

    FILE *f = NULL;

    if ((f = fopen(file_name, "w")) == NULL)
    {
        return ERR_FILE;
    }

    rc = dots_info_output(f, model.dots);
    if (rc != OK)
    {
        fclose(f);
        return rc;
    }

    rc = lines_info_output(f, model.lines);

    fclose(f);

    return rc;
}

int model_draw(const model_t& model, const canvas_t& canvas)
{
    int rc = model_check_arrays(model);
    if (rc != OK)
    {
        return rc;
    }

    rc = lib_canvas_clear_screen(canvas.scene);
    if (rc != OK)
    {
        return rc;
    }

    rc = lines_draw(model.lines, model.dots, canvas);

    return rc;
}


int model_shift(model_t& model, const shift_params_t& shifts)
{
    int rc = model_check_arrays(model);
    if (rc != OK)
    {
        return rc;
    }

    rc = dots_info_shift(model.dots, shifts);
    if (rc != OK)
    {
        return rc;
    }

    rc = dot_shift(model.centre, shifts);

    return rc;
}

int model_scale(model_t& model, const scale_params_t& coeffs)
{
    int rc = model_check_arrays(model);
    if (rc != OK)
    {
        return rc;
    }

    rc = dots_info_scale(model.dots, coeffs, model.centre);

    return rc;
}

int model_turn(model_t& model, const turn_params_t &angles)
{
    int rc = model_check_arrays(model);
    if (rc != OK)
    {
        return rc;
    }

    rc = dots_info_turn(model.dots, angles, model.centre);

    return rc;
}
