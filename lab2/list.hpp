#ifndef _LIST_HPP_
#define _LIST_HPP_

#include <memory>
#include <ctime>
#include <iterator>

#include "list.h"

// создание нового узла и вставка перед
template <typename T>
std::shared_ptr<ListNode<T>> List<T>::initNode(const T &data, std::shared_ptr<ListNode<T>> ptrNode)
{
    time_t t_time = time(NULL);
    std::shared_ptr<ListNode<T>> newNode;
    newNode = std::make_shared<ListNode<T>>();
    // ошибка выделения памяти
    if (!newNode)
    {
        throw ListMemoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    newNode->setData(data);
    newNode->setNext(ptrNode);
    this->len += 1;

    return newNode;
}

// добавление списка в конец существующего (без изменения добавляемого)
template <typename T>
void List<T>::addList(const List &ListToAdd)
{
    T data = ListToAdd.head->getData();
    std::shared_ptr<ListNode<T>> nextNode = ListToAdd.head->getNext();
    std::shared_ptr<ListNode<T>> nodeToAdd = initNode(data, nextNode);
    std::shared_ptr<ListNode<T>> cur = this->head;
    // добавление первого узла нового списка
    // добавление в пустой
    if (this->isEmpty())
    {
        cur = nodeToAdd;
        this->head = cur;
    }
    else
    {
        // доходим до конца
        for (; cur->getNext(); cur = cur->getNext())
            ;
        cur->setNext(nodeToAdd);
        cur = cur->getNext();
    }
    // добавление остальных
    std::shared_ptr<ListNode<T>> curToAdd = nextNode;

    for (; curToAdd; curToAdd = curToAdd->getNext(), cur = cur->getNext())
    {
        data = curToAdd->getData();
        nextNode = curToAdd->getNext();
        nodeToAdd = initNode(data, nextNode);
        cur->setNext(nodeToAdd);
    }
    // добавление последнего как хвоста
    this->tail = nodeToAdd;
}

// сравнение всех узлов 2 списков
template <typename T>
bool List<T>::isEqualTo(const List<T> &someList) const
{
    std::shared_ptr<ListNode<T>> curL = this->head;
    std::shared_ptr<ListNode<T>> curR = someList.head;
    for (; curL && curR && curL->getData() == curR->getData();)
    {
        curL = curL->getNext();
        curR = curR->getNext();
    }

    // дошли ли в сравнении до конца
    return (curL == nullptr && curR == nullptr) ? true : false;
}

// проверка на пустоту
template <typename T>
bool List<T>::isEmpty() const
{
    return (this->head == nullptr) ? true : false;
}


// конструктор по умолчанию - обнуление
template <typename T>
List<T>::List() : head(nullptr), tail(nullptr) {}

// явный конструктор-копирование из такого же списка
template <typename T>
List<T>::List(const List<T> &someList) : head(nullptr), tail(nullptr)
{
    this->extend(someList);
}

// конструктор-копирование по указателю-удаляет старый и создает новый
template <typename T>
List<T>::List(List<T> &&someList)
{
    // копирование
    this->len = someList->len;
    // reset из-за shared_ptr-удаляет старый объект и получает новый
    this->head.reset(someList->head);
    this->tail.reset(someList->tail);

    // зачистка старого
    someList->len = 0;
    someList->head = nullptr;
    someList->tail = nullptr;
}

// конструктор с использованием списка инициализации
template <typename T>
List<T>::List(std::initializer_list<T> someList) : head(nullptr), tail(nullptr)
{
    for (const auto &data : someList)
    {
        append(data);
    }
}

// конструктор с использованием обычного списка соответствующего типа
template <typename T>
List<T>::List(const T *arr, const int len)
{
    for (int i = 0; i < len; i++)
    {
        this->append(arr[i]);
    }
}

// конструктор-копирование с итератором (для vect)
template <typename T>
template <typename T_>
List<T>::List(T_ begin, T_ end)
{
    for (auto it = begin; it != end; it++)
    {
        this->append(*it);
    }
}

// простое обнуление списка
template <typename T>
List<T> &List<T>::clear()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->len = 0;

    return *this;
}

// перегрузка оператора присваивания
template <typename T>
List<T> &List<T>::operator=(const List &someList)
{
    if (this != &someList) // если пользователь совсем издевается...
    {
        this->clear();
        this->extend(someList);
    }

    return *this;
}

template <typename T>
List<T> &List<T>::operator=(List &&someList)
{
    if (this != someList) // и снова...
    {
        this->clear();
        this->len = someList->len;
        this->head = someList->head;
        this->tail = someList->tail;

        //someList->clear(); - rvalue!

        someList->len = 0;
        someList->head = nullptr;
        someList->tail = nullptr;
    }

    return *this;
}

template <typename T>
List<T> &List<T>::operator=(std::initializer_list<T> someList)
{
    if (this != someList)
    {
        this->clear();
        this->len = someList->getLen;
        this->head = someList->begin;
        this->tail = someList->end;

        someList->getLen = 0;
        someList->begin = nullptr;
        someList->end = nullptr;
    }

    return *this;
}

// с 1 итератором
template <typename T>
template <typename T_>
List<T> &operator=(T_ begin);
{
    for (auto it = begin; it != end; it++)
    {
        this->append(*it);
    }
}

// перегрузка оператора сложения и
// add~+data
template <typename T>
List<T> List<T>::add(const T &data) const
{
    List<T> newList(*this); // чтобы не испортить существующий
    newList.append(data);
    return newList;
}

template <typename T>
List<T> List<T>::operator+(const T &data) const
{
    return *this->add(data);
}

// addlist~+list
template <typename T>
List<T> List<T>::addlist(const List<T> &someList) const
{
    List<T> newList(*this);
    newList.extend(someList);
    return newList;
}

template <typename T>
List<T> List<T>::operator+(const List<T> &someList) const
{
    return *this->addlist(someList);
}

// перегрузка оператора сложения с присваиванием и
// append~+=data
template <typename T>
List<T> &List<T>::append(const T &data)
{
    std::shared_ptr<ListNode<T>> newNode = initNode(data);

    if (this->isEmpty())
    {
        this->head = newNode;
    }
    else
    {
        this->tail->setNext(newNode);
    }
    this->tail = newNode;

    return *this;
}

template <typename T>
List<T> &List<T>::operator+=(const T &data)
{
    this->append(data);
    return *this;
}

// extend~+=List
template <typename T>
List<T> &List<T>::extend(const List &ListToAdd)
{
    if (ListToAdd.isEmpty())
    {
        return *this;
    }

    if (this == &ListToAdd)
    {
        List<T> ListCopy;
        ListCopy = ListToAdd;
        addList(ListCopy);
    }
    else
    {
        addList(ListToAdd);
    }

    return *this;
}

template <typename T>
List<T> &List<T>::operator+=(const List<T> &someList)
{
    this->extend(someList);
    return *this;
}

// перегрузка оператора равенства и isEqual~==
template <typename T>
bool List<T>::isEqual(const List<T> &someList) const
{
    return isEqualTo(someList);
}

template <typename T>
bool List<T>::operator==(const List &someList) const
{
    return isEqualTo(someList);
}

// перегрузка оператора неравенства и isNotEqual~!=
template <typename T>
bool List<T>::isNotEqual(const List<T> &someList) const
{
    return !isEqualTo(someList);
}

template <typename T>
bool List<T>::operator!=(const List &someList) const
{
    return !isEqualTo(someList);
}

// вставка и удаление по месту
template <typename T>
List<T> &List<T>::insert(const T &data, const ListIter<T> &iter)
{
    time_t t_time = time(NULL);
    std::shared_ptr<ListNode<T>> curNode = this->head;
    std::shared_ptr<ListNode<T>> tmp = nullptr;
    ListIter<T> cur = this->begin();

    // если вставляем в пустой список на 0 позицию
    if (this->head == nullptr && cur == iter)
    {
        std::shared_ptr<ListNode<T>> newNode = initNode(data);
        this->head = newNode;
        this->tail = newNode;
        return *this;
    }
    // доходим до нужной позиции
    for (; curNode && cur != iter; tmp = curNode, curNode = curNode->getNext(), cur.next())
        ;

    // вышли за границы
    if (curNode == nullptr)
    {
        throw ListRangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    // вставка между временным и текущим
    std::shared_ptr<ListNode<T>> newNode = initNode(data, curNode);

    if (curNode == this->head)
    {
        this->head = newNode;
    }
    else
    {
        tmp->setNext(newNode);
    }

    return *this;
}

template <typename T>
const T List<T>::remove(const ListIter<T> &iter)
{
    time_t t_time = time(NULL);
    // удаление из пустого списка
    if (this->isEmpty())
    {
        throw ListEmptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    std::shared_ptr<ListNode<T>> curNode = this->head;
    std::shared_ptr<ListNode<T>> tmp = nullptr;
    ListIter<T> cur = this->begin();

    // доходим до нужной позиции
    for (; curNode && cur != iter; tmp = curNode, curNode = curNode->getNext(), cur.next())
        ;

    // вышли за границы
    if (curNode == nullptr)
    {
        throw ListRangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    // возвращаемая информация
    T retData = iter.getCur();

    // удаляем из списка
    if (curNode->getNext() == nullptr)
    {
        this->tail = tmp;
    }

    if (curNode == this->head)
    {
        this->head = this->head->getNext();
    }
    else
    {
        tmp->setNext(curNode->getNext());
    }
    this->len -= 1;

    return retData;
}

// удаление последнего
template <typename T>
const T List<T>::pop()
{
    time_t t_time = time(NULL);
    // удаление из пустого списка
    if (this->isEmpty())
    {
        throw ListEmptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    ListIter<T> iter = this->end();
    return remove(iter);
}

// создание итераторов
template <typename T>
ListIter<T> List<T>::begin()
{
    return ListIter<T>(head);
}

template <typename T>
ListIter<T> List<T>::end()
{
    return ListIter<T>(tail);
}

template <typename T>
ConstListIter<T> List<T>::c_begin() const
{
    return ConstListIter<T>(head);
}

template <typename T>
ConstListIter<T> List<T>::c_end() const
{
    return ConstListIter<T>(tail);
}

// вывод информации о списке
template <typename T>
std::ostream &operator<<(std::ostream &stream, List<T> &list)
{
    stream << "List";
    ListIter<T> iter = list.begin();
    if (!iter.checkRange())
    {
        stream << " is empty";
    }
    else
    {
        stream << ":";
        for (; iter.checkRange(); iter.next())
        {
            stream << " " << iter.getCur();
        }
    }

    return stream;
}

#endif
