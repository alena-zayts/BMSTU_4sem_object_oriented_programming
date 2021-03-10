#include "commands.h"

int command_run(const command_t &command)
{
    static model_t model = model_init();
    int rc = OK;

    switch (command.com_number)
    {
    case COM_DOWNLOAD:
        rc = model_download(model, command.file_name);
        break;
    case COM_UPLOAD:
        rc = model_upload(model, command.file_name);
        break;
    case COM_SHIFT:
        rc = model_shift(model, command.shift_params);
        break;
    case COM_SCALE:
        rc = model_scale(model, command.scale_params);
        break;
    case COM_TURN:
        rc = model_turn(model, command.turn_params);
        break;
    case COM_DRAW:
        rc = model_draw(model, command.canvas);
        break;
    case COM_QUIT:
        model_free(model);
        break;
    default:
        rc = ERR_COMMAND;
    }

    return rc;
}
