#ifndef _BASE_H_
#define _BASE_H_

#include <iostream>

// Базовый класс списка
class ListBase
{
// чтобы производные классы имели доступ к полю
protected:
    size_t len;

public:
    // конструктор по умолчанию
    ListBase();
    // деструктор virtual, чтобы деструктор порожденного класса его вызвал, по умолчанию
    virtual ~ListBase() = default;

    // получить длину списка
    size_t getLen() const;
};

#endif
