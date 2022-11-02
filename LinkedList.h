#ifndef LINKEDLIST_H
#define LINKEDLIST_H

enum Mode{
    Circular,
    Singly,
    Doubly
};

template<class type> struct _Singly{
    type data;
    _Singly<type> *next;
};

template<class type> struct _Doubly{
    type data;
    _Doubly<type> *next;
    _Doubly<type> *prev;
};

template<class type> struct _Circular{
    type data;
    _Circular<type> *next;
    _Circular<type> *prev;
};

template<class type, Mode mode> class LinkedList{};

template<class type> class LinkedList<type, Singly>{
    private:
        using Node = _Singly<type>;
        Node *head;
        Node *tail;

    public:
        
};

#endif