#ifndef COMMANDS_H
#define COMMANDS_H

#define COM_DOWNLOAD 1
#define COM_UPLOAD 2
#define COM_SHIFT 3
#define COM_SCALE 4
#define COM_TURN 5
#define COM_DRAW 6
#define COM_QUIT 7

#include "model.h"

typedef struct command command_t;
struct command
{
    int com_number;
    union
    {
        const char *file_name;
        shift_params_t shift_params;
        scale_params_t scale_params;
        turn_params_t turn_params;
        canvas_t canvas;
    };
};

int command_run(const command_t &command);

#endif // COMMANDS_H
