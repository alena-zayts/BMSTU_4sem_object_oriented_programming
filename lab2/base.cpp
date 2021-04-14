#include "base.h"

// конструктор по умолчанию
ListBase::ListBase() : len(0) {}

// деструктор по умолчанию
ListBase::~ListBase() = default;

// получить длину списка
size_t ListBase::getLen() const
{
    return len;
}
