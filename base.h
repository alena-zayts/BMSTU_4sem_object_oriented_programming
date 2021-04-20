#ifndef _BASE_H_
#define _BASE_H_

#include <iostream>

// Базовый класс списка
class ListBase
{
public:
    // конструктор по умолчанию
    ListBase();
    // деструктор virtual, чтобы деструктор порожденного класса его вызвал, по умолчанию
    virtual ~ListBase() = 0;

    // получить длину списка
    size_t getLen() const;

// чтобы производные классы имели доступ к полю
protected:
    size_t len;
};

#endif
