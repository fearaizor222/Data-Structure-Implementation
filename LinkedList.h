#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <initializer_list>
#include "DArray.h"
#include <type_traits>

enum Mode{
    Circular,
    Singly,
    Doubly
};

template<class type, Mode mode> class LinkedList{};

template<class type> class LinkedList<type, Singly>{
    public:
        struct Node{
            type data;
            Node *next;

            Node(type data){
                this->data = data;
                next = nullptr;
            }
        };

        LinkedList(){
            head = tail = nullptr;
            length = 0;
        }

        LinkedList(std::initializer_list<type> other) : LinkedList(){
            typename std::initializer_list<type>::iterator it = other.begin();

            while(it != other.end()){
                this->addBack(*it);
                it++;
            }
        }

        LinkedList(const LinkedList<type, Singly> &other) : LinkedList(){
            Node *temp = other.head;

            while(temp != nullptr){
                this->addBack(temp->data);
                temp = temp->next;
            }
        }

        LinkedList(type *ptr, int length) : LinkedList(){
            for(int i = 0; i<length; i++){
                this->addBack(ptr[i]);
            }
        }

        LinkedList(DArray<type> other) : LinkedList(){
            for(int i = 0; i<other.size(); i++){
                this->addBack(other[i]);
            }
        }

        template<class otherType, Mode otherMode> LinkedList<type, Singly> &operator=(const LinkedList<otherType, otherMode> &other){
            this->clear();
            typename LinkedList<otherType, otherMode>::Node *temp = other.getHead();

            while(temp != nullptr){
                this->addBack((type)temp->data);
                temp = temp->next;
            }

            return *this;
        }

        LinkedList<type, Singly> &operator=(const LinkedList<type, Singly> &other){
            if(this == &other) return *this;

            this->clear();
            Node *temp = other.head;

            while(temp != nullptr){
                this->addBack(temp->data);
                temp = temp->next;
            }

            return *this;
        }

        template<class otherType> LinkedList<type, Singly> &operator=(DArray<otherType> other){
            this->clear();
            for(int i = 0; i<other.size(); i++){
                this->addBack((type)other[i]);
            }

            return *this;
        }

        template<class otherType> LinkedList<type, Singly> &operator=(std::initializer_list<otherType> other){
            this->clear();
            typename std::initializer_list<otherType>::iterator it = other.begin();

            while(it != other.end()){
                this->addBack((type)(*it));
                it++;
            }

            return *this;
        }

        LinkedList<type, Singly> range(int start, int end){
            int counter = 0;
            Node *temp = head;

            while(counter < start){
                temp = temp->next;
                counter++;
            }

            LinkedList<type, Singly> tempo;
            for(int i = 0; i<end - start; i++){
                tempo.addBack(temp->data);
                temp = temp->next;
            }

            return tempo;
        }

        void extend(const LinkedList<type, Singly> &other){
            Node *temp = other.head;
            
            while(temp != nullptr){
                this->addBack(temp->data);
                temp = temp->next;
            }
        }

        void extend(std::initializer_list<type> other){
            typename std::initializer_list<type>::iterator it = other.begin();

            while(it != other.end()){
                this->addBack(*it);
                it++;
            }
        }

        void extend(DArray<type> other){
            for(int i = 0; i<other.size(); i++){
                this->addBack(other[i]);
            }
        }

        type &at(int index){
            Node *temp = head;
            int internal_index = 0;

            if(index >= length) throw std::invalid_argument("Out of bound");
            else if(index < 0 && length + index >= 0){
                while(internal_index < length + index){
                    temp = temp->next;
                    internal_index++;
                }
                
                return temp->data;
            }

            while(internal_index < index){
                    temp = temp->next;
                    internal_index++;
                }

            return temp->data;
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

        void deleteBack(){
            if(head == nullptr) return;
            else if(head->next == nullptr){
                Node *temp = head;
                delete temp;
                head = nullptr;

                length--;
                return;
            }
            else{
                Node *temp1 = head;

                while(temp1->next->next != nullptr){
                    temp1 = temp1->next;
                }

                Node *temp2 = temp1->next;
                temp1->next = nullptr;
                tail = temp1;
                delete temp2;

                length--;
            }

        }

        void deleteFront(){
            if(head == nullptr) return;
            else if(head->next == nullptr){
                Node *temp = head;
                delete temp;
                head = nullptr;

                length--;
                return;
            }
            else{
                Node *temp = head;
                head = head->next;
                delete temp;

                length--;
            }
        }

        void deleteIndex(int index){
            if(head == nullptr) return;
            else if(head->next == nullptr){
                Node *temp = head;
                delete temp;
                head = nullptr;

                length--;
                return;
            }
            else{
                Node *temp1 = head;
                int counter = 0;

                while(temp1->next->next != nullptr && counter < index-1){
                    temp1 = temp1->next;
                    counter++;
                }

                Node *temp2 = temp1->next;
                temp1->next = temp2->next;
                delete temp2;

                length--;
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

        Node *getHead() const {
            return head;
        }

        void clear(){
            Node *temp1 = head;

            while(temp1 != nullptr){
                Node *temp2 = temp1;
                temp1 = temp2->next;
                delete temp2;
            }

            head = tail = nullptr;
            length = 0;
        }

        ~LinkedList(){
            this->clear();
        }

    private:
        Node *head;
        Node *tail;
        int length;

};

template<class type> class LinkedList<type, Doubly>{
    public:
        struct Node{
            type data;
            Node *next;
            Node *prev;

            Node(type data){
                this->data = data;
                next = nullptr;
                prev = nullptr;
            }
        };

    private:
        Node *head;
        Node *tail;
        int length;
};

template<class type> class LinkedList<type, Circular>{
    public:
        struct Node{
            type data;
            Node *next;
            Node *prev;

            Node(type data){
                this->data = data;
                next = nullptr;
                prev = nullptr;
            }
        };

    private:
        Node *head;
        Node *tail;
        int length;
};

#endif