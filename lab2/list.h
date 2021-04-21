#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <stdarg.h>
#include <iterator>

#include "errors.h"
#include "base.h"
#include "node.h"
#include "iterator.h"

// шаблон класса-списка
template <typename T>
// наследование public-ничего не меняется
class List : public ListBase
{
public:
    // конструктор по умолчанию-обнуление
    List();
    // явный конструктор-копирование из такого же списка
    explicit List(const List<T> &someList);
    // конструктор перемещения: переносит someList на this
    List(List<T> &&someList);
    // конструктор с использованием списка инициализации
    List(std::initializer_list<T> someList);
    // конструктор с использованием обычного списка соответствующего типа
    List(const T *arr, const int len);
    // конструктор-копирование с итератором (для vect)
    template <typename T_>
    List(T_ begin, T_ end);
    // деструктор virtual, чтобы деструктор порожденного класса его вызвал, по умолчанию
    virtual ~List() = default;

    // простое обнуление списка
    List<T> &clear();

    // перегрузка оператора присваивания
    List<T> &operator=(const List<T> &someList);
    List<T> &operator=(List<T> &&someList);
    List<T> &operator=(std::initializer_list<T> someList);
    // с 1 итератором
    template <typename T_>                                //new
    List<T> &operator=(T_ begin);

    // возвращают новый список
    // перегрузка оператора сложения и
    // add~+data
    List<T> add(const T &data) const;
    List<T> operator+(const T &data) const;
    // addlist~+list
    List<T> addlist(const List<T> &someList) const;
    template <typename T_>
    List<T> addlist(T_ begin, T_ end) const;                //new
    List<T> operator+(const List<T> &someList) const;

    // изменяют текущий список и возвращают ссылку на себя
    // перегрузка оператора сложения с присваиванием и
    // append~+=data
    List<T> &append(const T &data);
    List<T> &operator+=(const T &data);
    // extend~+=List
    List<T> &extend(const List<T> &someList);
    template <typename T_>
    List<T> &extend(T_ begin, T_ end);                       //new
    List<T> &operator+=(const List<T> &someList);

    // перегрузка оператора равенства и isEqual~==
    bool isEqual(const List<T> &someList) const;
    bool operator==(const List<T> &someList) const;
    // перегрузка оператора неравенства и isNotEqual~!=
    bool isNotEqual(const List<T> &someList) const;
    bool operator!=(const List<T> &someList) const;

    // вставка                                              // newwwwwwwwwwwwwwwwwwwww
    List<T> &pushHead(const T &data);
    List<T> &pushHead(const T *arr, const int len);
    template <typename T_>
    List<T> &pushHead(T_ begin, T_ end);
    List<T> &pushTail(const T &data);
    List<T> &pushTail(const T *arr, const int len);
    template <typename T_>
    List<T> &pushTail(T_ begin, T_ end);
    List<T> &pushIter(const T &data, const ListIter<T> &iter); // (not new)
    List<T> &pushIter(const T *arr, const int len, const ListIter<T> &iter);
    template <typename T_>
    List<T> &pushIter(T_ begin, T_ end, const ListIter<T> &iter);

    // удаление
    const T popHead();                                              // new
    const T popTail();                                              // new
    const T popIter(ListIter<T> &iter);
    void remove(const ListIter<T> &begin, const ListIter<T> &end);  //new

    // создание итераторов
    ListIter<T> begin();
    ListIter<T> end();
    // константные итераторы
    ConstListIter<T> begin() const; // добавить реализацию
    ConstListIter<T> end() const;   // добавить реализацию
    ConstListIter<T> c_begin() const;
    ConstListIter<T> c_end() const;

private:
    // указатель на голову
    std::shared_ptr<ListNode<T>> head;
    // указатель на хвост
    std::shared_ptr<ListNode<T>> tail;

    // создание нового узла и вставка перед
    std::shared_ptr<ListNode<T>> initNode(const T &data, std::shared_ptr<ListNode<T>> ptrNode = nullptr);
    // добавление списка в конец существующего
    void addList(const List<T> &ListToAdd);
    // сравнение всех узлов 2 списков
    bool isEqualTo(const List<T> &someList) const;
    // проверка на пустоту
    bool isEmpty() const;
};

#endif
