#ifndef _BASE_HPP_
#define _BASE_HPP_

#include "base.h"

// конструктор по умолчанию
ListBase::ListBase() : len(0) {}

// получить длину списка
size_t ListBase::getLen() const
{
    return len;
}

#endif
