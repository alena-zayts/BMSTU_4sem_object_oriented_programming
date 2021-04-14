#ifndef _ERRORS_H_
#define _ERRORS_H_

#include <exception>

// базовый класс ошибок
class ListErrorBase : public std::exception
{
    // чтобы производные классы имели доступ
protected:
    std::string errorMessage;
public:
    // явный конструктор-формирование сообщения об ошибке
    explicit ListErrorBase(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info)
    {
        errorMessage = "In " + filename +
                  "\nInside " + classname + " class" +
                  "\nAt line " + std::to_string(line) +
                  "\nAt time " + time +
                  "\nOccured error: " + info;
    }
    // noexcept-для отработки всех деструкторов
    // override-переопределение
    virtual const char *what() const noexcept override
    {
        return errorMessage.c_str();
    }
};

// частные ошибки наследуют все от базовой
// класс ошибки выделения памяти
class ListMemoryError : public ListErrorBase
{
public:
    ListMemoryError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Memory allocation error") : ListErrorBase(filename, classname, line, time, info) {}
};

// класс ошибки удаления элементов из пустого списка
class ListEmptyError : public ListErrorBase
{
public:
    ListEmptyError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "List is empty") : ListErrorBase(filename, classname, line, time, info) {}
};

// класс ошибки выхода за пределы списка
class ListRangeError : public ListErrorBase
{
public:
    ListRangeError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Index out of range") : ListErrorBase(filename, classname, line, time, info) {}
};

// класс ошибки неверного итератора (объект уже удален
class ListIteratorError : public ListErrorBase
{
public:
    ListIteratorError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Invalid iterator") : ListErrorBase(filename, classname, line, time, info) {}
};

#endif
