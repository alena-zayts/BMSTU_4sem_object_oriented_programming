#include "lines.h"

int lines_info_initialize(lines_info_t& lines_info, line_t * const arr, const int& amount)
{
    lines_info.arr = arr;
    lines_info.amount = amount;

    return OK;
}

int lines_info_check_array(const lines_info_t& lines_info)
{
    if (!lines_info.arr || !lines_info.amount)
    {
        return ERR_NO_FIGURE;
    }

    return OK;
}

int lines_info_free_arr(lines_info_t& lines_info)
{
    free(lines_info.arr);
    lines_info.amount = 0;

    return OK;
}

int lines_info_read_amount(int &amount, FILE* f)
{
    if ((fscanf(f, "%d", &amount)) != 1)
    {
        return ERR_INPUT;
    }

    if (amount < 1)
    {
        return ERR_LINES_AMOUNT;
    }

    return OK;
}

int lines_info_allocate_arr(lines_info_t& lines_info)
{
    line_t* arr_tmp = (line_t*) malloc(lines_info.amount * sizeof(line_t));

    if (!arr_tmp)
    {
        return ERR_MEM;
    }

    lines_info.arr = arr_tmp;

    return OK;
}

int lines_arr_read(line_t *lines_arr, const int& amount, FILE* f)
{
    if (!lines_arr)
    {
        return ERR_NO_FIGURE;
    }

    if (!f)
    {
        return ERR_FILE;
    }

    int rc = OK;
    for (int i = 0; (i < amount) && (rc == OK); i++)
    {
        if ((fscanf(f, "%d %d", &lines_arr[i].dot_1, &lines_arr[i].dot_2)) != 2)
        {
            rc = ERR_INPUT;
        }
    }

    return rc;
}


int lines_info_input(lines_info_t& lines_info, FILE* f)
{
    if (!f)
    {
        return ERR_FILE;
    }

    int rc = lines_info_read_amount(lines_info.amount, f);
    if (rc != OK)
    {
        return rc;
    }

    rc = lines_info_allocate_arr(lines_info);
    if (rc != OK)
    {
        return rc;
    }

    rc = lines_arr_read(lines_info.arr, lines_info.amount, f);
    if (rc != OK)
    {
        lines_info_free_arr(lines_info);
    }

    return rc;
}

int lines_arr_output(const line_t* lines_arr, const int& amount, FILE* f)
{
    if (!f)
    {
        return ERR_FILE;
    }

    if (!lines_arr)
    {
        return ERR_NO_FIGURE;
    }

    fprintf(f, "%d\n", amount);
    for (int i = 0; i < amount; i++)
    {
        fprintf(f, "%d %d\n", lines_arr[i].dot_1, lines_arr[i].dot_2);
    }

    return OK;
}

int lines_info_output(FILE* f, const lines_info_t& lines_info)
{
    if (!f)
    {
        return ERR_FILE;
    }

    int rc = lines_arr_output(lines_info.arr, lines_info.amount, f);

    return rc;
}

int line_draw(const line_t& line, const dot_t* const dots_arr, const canvas_t& canvas)
{
    if (!dots_arr)
    {
        return ERR_NO_FIGURE;
    }

    dot_t dot1 = dots_arr[line.dot_1];
    dot_t dot2 = dots_arr[line.dot_2];

    int rc = lib_canvas_draw_line(canvas, dot1, dot2);

    return rc;
}

int lines_draw(const lines_info_t& lines_info, const dots_info_t& dots_info, const canvas_t& canvas)
{
    int rc = OK;

    for (int i = 0; (i < lines_info.amount) && (rc == OK); i++)
    {
        rc = line_draw(lines_info.arr[i], dots_info.arr, canvas);
    }

    return rc;
}



