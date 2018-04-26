#ifndef stack_h
#define stack_h
#include <iostream>

template <class T>
class Stack
{
    struct Node
    {
        T data;
        Node* _next;
        Node(T data, Node* _next = NULL): data(data), _next(_next)
        {}
    };
    Node* _top = NULL;
    int _size = 0;
public:
    Stack() = default;
    explicit Stack(const Stack<T>&);
    ~Stack();
    inline int size()const;
    inline bool empty()const;
    inline T top()const;
    void push(T);
    void pop();
};

template <class T>
Stack<T>::~Stack()
{
    while(_top != NULL){
        Node* temp = _top;
        _top = _top->_next;
        delete temp;
    }
}

template <class T>
Stack<T>::Stack(const Stack<T>& a) : _size(a._size)
{
    Node* t = a._top;
    T* tab = new T[_size];
    for(int i=0; i<_size && t != NULL; ++i){
        tab[i] = t->data;
        t = t->_next;
    }
    for(int i=_size-1; i>=0; i--)
        this->push(tab[i]);

    delete[] tab;
}

template <class T>
inline int Stack<T>::size()const
{
    return _size;
}

template <class T>
inline bool Stack<T>::empty()const
{
    return _top? false : true;
}

template <class T>
inline T Stack<T>::top()const
{
    return _top? _top->data : T();
}

template <class T>
void Stack<T>::push(T data)
{
    Node* temp = new Node(data, _top);
    _top = temp;
    _size++;
}

template <class T>
void Stack<T>::pop()
{
    Node* temp = _top;
    _top = _top->_next;
    delete temp;
    _size--;
}


#endif // stack_h
