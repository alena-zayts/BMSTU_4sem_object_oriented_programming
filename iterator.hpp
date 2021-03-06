#ifndef _LISTITERATOR_HPP_
#define _LISTITERATOR_HPP_

#include <ctime>

#include "iterator.h"

// конструктор по умолчанию-нулевой указатель
template <typename T>
ListIterBase<T>::ListIterBase()
{
    this->ptrCur.lock() = nullptr; //lock конвертирует в shared_ptr
}

// конструктор-копия такого же итератора
template <typename T>
ListIterBase<T>::ListIterBase(const ListIterBase<T> &listIter) : ptrCur(listIter.ptrCur) {}

// конструктор с начальным узлом
template <typename T>
ListIterBase<T>::ListIterBase(const std::shared_ptr<ListNode<T>> node) : ptrCur(node) {}

// доступ и переход к следующему
template <typename T>
ListIterBase<T> &ListIterBase<T>::next()
{
    // если объект уже удален
    if (this->ptrCur.expired())
    {
        time_t t_time = time(NULL);
        throw ListIteratorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    this->ptrCur = this->ptrCur.lock()->getNext();
    return *this;
}

// перегрузка оператора присваивания (конструктор копирования)
template <typename T>
ListIterBase<T> &ListIterBase<T>::operator=(const ListIterBase<T> &listIter)
{
    if (this != &listIter) // присваивание самому себе
    {
        this->ptrCur = listIter.ptrCur;
    }

    return *this;
}

// префиксный инкремент
template <typename T>
ListIterBase<T> &ListIterBase<T>::operator++()
{
    this->next();
    return *this;
}

// постфиксный инкремент
template <typename T>
ListIterBase<T> ListIterBase<T>::operator++(int)
{
    ListIterBase<T> tmp(*this);
    this->operator++();
    return tmp;
}

// равенство/неравенство
template <typename T>
bool ListIterBase<T>::operator==(const ListIterBase<T> &listIter) const
{
    return this->ptrCur.lock() == listIter.ptrCur.lock();
}

template <typename T>
bool ListIterBase<T>::operator!=(const ListIterBase<T> &listIter) const
{
    return this->ptrCur.lock() != listIter.ptrCur.lock();
}

// проверка на нахождение в границах
template <typename T>
bool ListIterBase<T>::checkRange() const
{
    return (this->ptrCur.lock() == nullptr) ? false : true;
}


// шаблон класса-неконстантного итератора списка
// конструктор по умолчанию-нулевой указатель
template <typename T>
ListIter<T>::ListIter()
{
    this->ptrCur.lock() = nullptr;
}

// конструктор-копия такого же итератора
template <typename T>
ListIter<T>::ListIter(const ListIter<T> &listIter)
{
    this->ptrCur = listIter.ptrCur;
}

// конструктор с начальным узлом
template <typename T>
ListIter<T>::ListIter(const std::shared_ptr<ListNode<T>> node)
{
    this->ptrCur = node;
}

// получение текущего и следующего
template <typename T>
T &ListIter<T>::getCur()
{
    if (this->ptrCur.expired())
    {
        time_t t_time = time(NULL);
        throw ListIteratorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return this->ptrCur.lock()->getPtrData();
}

template <typename T>
const T &ListIter<T>::getCur() const
{
    if (this->ptrCur.expired())
    {
        time_t t_time = time(NULL);
        throw ListIteratorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return this->ptrCur.lock()->getPtrData();
}

template <typename T>
T &ListIter<T>::getNext()
{
    if (this->ptrCur.expired() || this->ptrCur.lock() == this->end() || this->ptrCur.next().lock() == this->end())
    {
        time_t t_time = time(NULL);
        throw ListIteratorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return this->ptrCur.next().lock()->getPtrData();
}

template <typename T>
const T &ListIter<T>::getNext() const
{
    if (this->ptrCur.expired() || this->ptrCur.lock() == this->c_end() || this->ptrCur.next().lock() == this->c_end())
    {
        time_t t_time = time(NULL);
        throw ListIteratorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return this->ptrCur.next().lock()->getPtrData();
}

// перегрузка операторов
// оператор присваивания (копирование)
template <typename T>
ListIter<T> &ListIter<T>::operator=(const ListIter<T> &listIter)
{
    if (this != &listIter)
    {
        this->ptrCur = listIter.ptrCur;
    }

    return *this;
}

//template <typename T>
//ListIter<T> &ListIter<T>::operator=(const ListIterBase<T> &listIter)
//{
//    this->ptrCur = listIter.ptrCur;

//    return *this;
//}

template <typename T>
T &ListIter<T>::operator*()
{
    if (this->ptrCur.expired())
    {
        time_t t_time = time(NULL);
        throw ListIteratorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return this->ptrCur.lock()->getPtrData();
}

template <typename T>
const T &ListIter<T>::operator*() const
{
    if (this->ptrCur.expired())
    {
        time_t t_time = time(NULL);
        throw ListIteratorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return this->ptrCur.lock()->getPtrData();
}

template <typename T>
T *ListIter<T>::operator->()
{
    if (this->ptrCur.expired())
    {
        time_t t_time = time(NULL);
        throw ListIteratorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return &this->ptrCur.lock()->getPtrData();
}

template <typename T>
const T *ListIter<T>::operator->() const
{
    if (this->ptrCur.expired())
    {
        time_t t_time = time(NULL);
        throw ListIteratorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return &this->ptrCur.lock()->getPtrData();
}

// существует ли еще объект
template <typename T>
ListIter<T>::operator bool() const
{
    return &this->ptrCur.expired();
}


// шаблон класса-константного итератора списка
// конструктор по умолчанию-нулевой указатель
template <typename T>
ConstListIter<T>::ConstListIter()
{
    this->ptrCur.lock() = nullptr;
}

// конструктор-копия такого же итератора
template <typename T>
ConstListIter<T>::ConstListIter(const ConstListIter<T> &listIter)
{
    this->ptrCur = listIter.ptrCur;
}

// конструктор с начальным узлом
template <typename T>
ConstListIter<T>::ConstListIter(const std::shared_ptr<ListNode<T>> node)
{
    this->ptrCur = node;
}

// получение текущего и следующего
template <typename T>
const T &ConstListIter<T>::getCur() const
{
    if (this->ptrCur.expired())
    {
        time_t t_time = time(NULL);
        throw ListIteratorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return this->ptrCur.lock()->getPtrData();
}

template <typename T>
const T &ConstListIter<T>::getNext() const
{
    if (this->ptrCur.expired() || this->ptrCur.lock() == this->c_end() || this->ptrCur.next().lock() == this->c_end())
    {
        time_t t_time = time(NULL);
        throw ListIteratorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return this->ptrCur.next().lock()->getPtrData();
}

// перегрузка операторов
// оператор присваивания (копирование)
template <typename T>
ConstListIter<T> &ConstListIter<T>::operator=(const ConstListIter<T> &listIter)
{
    if (this != &listIter)
    {
        this->ptrCur = listIter.ptrCur;
    }

    return *this;
}

template <typename T>
const T &ConstListIter<T>::operator*() const
{
    if (this->ptrCur.expired())
    {
        time_t t_time = time(NULL);
        throw ListIteratorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return this->ptrCur.lock()->getPtrData();
}

template <typename T>
const T *ConstListIter<T>::operator->() const
{
    if (this->ptrCur.expired())
    {
        time_t t_time = time(NULL);
        throw ListIteratorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return &this->ptrCur.lock()->getPtrData();
}

// существует ли еще объект
template <typename T>
ConstListIter<T>::operator bool() const
{
    return &this->ptrCur.expired();
}

#endif
