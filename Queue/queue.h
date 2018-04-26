#ifndef queue_h
#define queue_h
#include <iostream>

template <class T>
class Queue
{
    struct Node
    {
        T data;
        Node* _next;
        Node(T data, Node* _next = NULL) : data(data), _next(_next)
        {}
    };
    Node* _begin = NULL;
    Node* _end = NULL;
    int _size = 0;
public:
    Queue() = default;
    explicit Queue(const Queue<T>&);
    ~Queue();
    inline int size()const;
    inline bool empty()const;
    inline T front()const;
    inline T back()const;
    void push(T);
    void pop();
};

template <class T>
Queue<T>::~Queue()
{
    while(_begin != NULL){
        Node* temp = _begin;
        _begin = _begin->_next;
        delete temp;
    }
    delete _end;
}

template <class T>
Queue<T>::Queue(const Queue<T>& a) : _size(a._size)
{
    Node* temp = a._begin;
    while(temp != NULL){
        push(temp->data);
        temp = temp->_next;
    }
}

template <class T>
inline int Queue<T>::size()const
{
    return _size;
}

template <class T>
inline bool Queue<T>::empty()const
{
    return _begin? false : true;
}

template <class T>
inline T Queue<T>::front()const
{
    return _begin? _begin->data : T();
}

template <class T>
inline T Queue<T>::back()const
{
    return _end? _end->data : T();
}

template <class T>
void Queue<T>::push(T data)
{
    Node* temp = new Node(data);
    if(_begin == NULL){
        _begin = temp;
        _end = temp;
    }
    else
    {
        _end->_next = temp;
        _end = _end->_next;
    }
    _size++;
}

template <class T>
void Queue<T>::pop()
{
    Node* temp = _begin;
    _begin = _begin->_next;
    delete temp;
    _size--;
}


#endif // queue_h
