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

    _Singly(type data){
        this->data = data;
        next = nullptr;
    }
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
            Node *temp = new Node(data);

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

        void addFront(type data){
            Node *temp = new Node(data);

            if(head == nullptr){
                head = tail = temp;
                length = 1;
            }
            else{
                temp->next = head;
                head = temp;
                length++;
            }
        }

        void addIndex(type data, int index){
            if(index <= 0) this->addFront(data);
            else if(index > length) this->addBack(data);
            else{
                Node *temp = new Node(data);
                int internal_index = 0;
                Node *temp_head = head;

                while(internal_index < index - 1){
                    temp_head = temp_head->next;
                    internal_index++;
                }

                temp->next = temp_head->next;
                temp_head->next = temp;
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