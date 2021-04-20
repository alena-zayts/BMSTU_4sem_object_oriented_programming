#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include "node.h"

// шаблон класса-итератора базы
template <typename T>
//                                        категория итератора, значения
class ListIterBase : public std::iterator<std::input_iterator_tag, T>
{
public:
    // конструктор по умолчанию-нулевой указатель
    ListIterBase();
    // конструктор-копия такого же итератора
    ListIterBase(const ListIterBase<T> &listIter);
    // конструктор с начальным узлом
    ListIterBase(const std::shared_ptr<ListNode<T>> node);
    // деструктор по умолчанию
    virtual ~ListIterBase() = default;

    // доступ и переход к следующему
    ListIterBase<T> &next();

    // перегрузка оператора присваивания (конструктор копирования)
    ListIterBase<T> &operator=(const ListIterBase<T> &listIter);   
    // префиксный инкремент
    ListIterBase<T> &operator++();
    // постфиксный инкремент
    ListIterBase<T> operator++(int);
    // равенство/неравенство
    bool operator==(const ListIterBase<T> &listIter) const;
    bool operator!=(const ListIterBase<T> &listIter) const;

    // проверка на нахождение в границах
    bool checkRange() const;

protected:
    //std::weak_ptr может наблюдать и получать доступ к тому же объекту, на который указывает std::shared_ptr
    // (или другой std::weak_ptr), но не считаться владельцем этого объекта.
    std::weak_ptr<ListNode<T>> ptrCur;
};


// шаблон класса-неконстантного итератора списка
template <typename T>
class ListIter : public ListIterBase<T>
{
public:
    // конструктор по умолчанию-нулевой указатель
    ListIter();
    // конструктор-копия такого же итератора
    ListIter(const ListIter<T> &listIter);
    // конструктор с начальным узлом
    ListIter(const std::shared_ptr<ListNode<T>> node);

    // получение текущего и следующего
    T &getCur();
    const T &getCur() const;
    T &getNext();
    const T &getNext() const;

    // перегрузка операторов
    // оператор присваивания (копирование)
    ListIter<T> &operator=(const ListIter<T> &listIter);
    T &operator*();
    const T &operator*() const;
    T *operator->();
    const T *operator->() const;

    // существует ли еще объект
    operator bool() const;
};

// шаблон класса-константного итератора списка
template <typename T>
class ConstListIter : public ListIterBase<T>
{
public:
    // конструктор по умолчанию-нулевой указатель
    ConstListIter();
    // конструктор-копия такого же итератора
    ConstListIter(const ConstListIter<T> &listIter);
    // конструктор с начальным узлом
    ConstListIter(const std::shared_ptr<ListNode<T>> node);

    // получение текущего и следующего
    const T &getCur() const;
    const T &getNext() const;

    // перегрузка операторов
    // оператор присваивания (копирование)
    ConstListIter<T> &operator=(const ConstListIter<T> &listIter);    
    const T &operator*() const;
    const T *operator->() const;

    // существует ли еще объект
    operator bool() const;
};

#endif
