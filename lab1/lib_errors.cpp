#include "lib_errors.h"

int show_error(const int& error)
{
    switch (error)
    {
    case ERR_FILE:
        QMessageBox::critical(NULL, "Ошибка", "Ошибка при открытии файла.");
        break;
    case ERR_MEM:
        QMessageBox::critical(NULL, "Ошибка", "Ошибка при выделении памяти.");
        break;
    case ERR_INPUT:
        QMessageBox::critical(NULL, "Ошибка", "Ошибка при чтении чисел из файла.");
        break;
    case ERR_DOTS_AMOUNT:
        QMessageBox::critical(NULL, "Ошибка", "Неверное количество точек в файле."
                                              "Ожидалось не менее 2 точек.");
        break;
    case ERR_LINES_AMOUNT:
        QMessageBox::critical(NULL, "Ошибка", "Неверное количество линий в файле."
                                              "Ожидалось не менее 1 линии.");
        break;
    case ERR_NO_FIGURE:
        QMessageBox::critical(NULL, "Ошибка", "Фигура еще не была загружена.");
        break;
    case ERR_COMMAND:
        QMessageBox::critical(NULL, "Ошибка", "Неизвестная команда.");
        break;
    }

    return OK;
}
