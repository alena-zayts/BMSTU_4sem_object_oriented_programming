#ifndef _LISTNODE_HPP_
#define _LISTNODE_HPP_

#include "node.h"

// конструктор по умолчанию-обнуление
template <typename T>
ListNode<T>::ListNode() : data(0), next(nullptr) {}

// явный конструктор c 1 параметром-данные соответствующего типа
template <typename T>
ListNode<T>::ListNode(const T data) : data(data), next(nullptr) {}

// явный конструктор-копия-вставка перед
template <typename T>
ListNode<T>::ListNode(const std::shared_ptr<ListNode<T>> node) : data(node->data), next(node) {}

// конструктор с 2 параметрами-данные соответствующего типа и указатель на следующий элемент
template <typename T>
ListNode<T>::ListNode(const T data, const std::shared_ptr<ListNode<T>> nextNode) : data(data), next(nextNode) {}

// деструктор
template <typename T>
ListNode<T>::~ListNode()
{
    this->data = 0;
    this->next = nullptr;
}

// запись и чтение данных (по значению и по ссылке)
template <typename T>
void ListNode<T>::setData(const T data)
{
    this->data = data;
}

template <typename T>
T ListNode<T>::getData() const
{
    return this->data;
}

template <typename T>
T &ListNode<T>::getPtrData()
{
    return this->data;
}

// запись и чтение указателя на следующий узел
template <typename T>
void ListNode<T>::setNext(const std::shared_ptr<ListNode<T>> nextNode)
{
    this->next = nextNode;
}

template <typename T>
std::shared_ptr<ListNode<T>> ListNode<T>::getNext()
{
    return this->next;
}

// перегрузка операторов сравнения
template <typename T>
bool ListNode<T>::operator==(const ListNode &node) const
{
    return (this->data == node.data) ? true : false;
}

template <typename T>
bool ListNode<T>::operator!=(const ListNode &node) const
{
    return (this->data != node.data) ? true : false;
}

template <typename T>
bool ListNode<T>::operator>(const ListNode &node) const
{
    return (this->data > node.data) ? true : false;
}

template <typename T>
bool ListNode<T>::operator<(const ListNode &node) const
{
    return (this->data < node.data) ? true : false;
}

template <typename T>
bool ListNode<T>::operator>=(const ListNode &node) const
{
    return (this->data >= node.data) ? true : false;
}

template <typename T>
bool ListNode<T>::operator<=(const ListNode &node) const
{
    return (this->data <= node.data) ? true : false;
}

#endif
