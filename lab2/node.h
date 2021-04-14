#ifndef _NODE_H_
#define _NODE_H_

// шаблон классса - узел списка
template <typename T>
class ListNode
{
private:
    // информационная часть соответствующего типа
    T data;
    // указатель на следующий узел
    std::shared_ptr<ListNode<T>> next;

public:
    // конструктор по умолчанию-обнуление
    ListNode();
    // явный конструктор c 1 параметром-данные соответствующего типа
    explicit ListNode(const T data);
    // Умный указатель std::shared_ptr До тех пор, пока хотя бы один std::shared_ptr владеет ресурсом, этот
    // ресурс не будет уничтожен
    // явный конструктор-копия-вставка перед
    explicit ListNode(const std::shared_ptr<ListNode<T>> node);
    // конструктор с 2 параметрами-данные соответствующего типа и указатель на следующий элемент
    ListNode(const T data, const std::shared_ptr<ListNode<T>> nextNode);
    // деструктор virtual, чтобы деструктор порожденного класса его вызвал - простое зануление
    virtual ~ListNode();

    // запись и чтение информационной части (по значению и по ссылке)
    void setData(const T data);
    T getData() const;  // Константный метод—гарантирует, что не будет изменять объект или вызывать неконстантные методы
    T &getPtrData();

    // запись и чтение указателя на следующий узел
    void setNext(const std::shared_ptr<ListNode<T>> nextNode);
    std::shared_ptr<ListNode<T>> getNext();

    // перегрузка операторов сравнения
    bool operator==(const ListNode<T> &node) const;
    bool operator!=(const ListNode<T> &node) const;
    bool operator>(const ListNode<T> &node) const;
    bool operator<(const ListNode<T> &node) const;
    bool operator>=(const ListNode<T> &node) const;
    bool operator<=(const ListNode<T> &node) const;
};

#endif
