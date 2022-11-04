#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <initializer_list>

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
        int length;

    public:
        LinkedList(){
            head = tail = nullptr;
            length = 0;
        }

        LinkedList(std::initializer_list<type> data){
            head = tail = nullptr;
            length = 0;
            typename std::initializer_list<type>::iterator it = data.begin();

            while(it != data.end()){
                this->addBack(*it);
                it++;
            }
        }

        void addBack(type data){
            Node *temp = new Node;
            temp->data = data;
            temp->next = nullptr;

            if(head == nullptr){
                head = tail = temp;
                length = 1;
            }
            else{
                tail->next = temp;
                tail = temp;
                length++;
            }
        }

        int size(){
            return length;
        }

        void print(){
            Node *temp = head;

            while(temp != nullptr){
                std::cout<<temp->data<<" ";
                temp = temp->next;
            }

            std::cout<<"\n"<<length<<"\n";
        }

};

#endif