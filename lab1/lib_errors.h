#ifndef LIB_ERRORS_H
#define LIB_ERRORS_H

#define OK 0
#define ERR_FILE -1
#define ERR_MEM -2
#define ERR_INPUT -3
#define ERR_DOTS_AMOUNT -4
#define ERR_LINES_AMOUNT -5
#define ERR_NO_FIGURE -6
#define ERR_COMMAND -7

#include <QMessageBox>

int show_error(const int& error);

#endif // LIB_ERRORS_H
