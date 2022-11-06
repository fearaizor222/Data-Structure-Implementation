#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <initializer_list>

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

        LinkedList(std::initializer_list<type> data){
            head = tail = nullptr;
            length = 0;
            typename std::initializer_list<type>::iterator it = data.begin();

            while(it != data.end()){
                this->addBack(*it);
                it++;
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

        ~LinkedList(){
            Node *temp1 = head;

            while(temp1 != nullptr){
                Node *temp2 = temp1;
                temp1 = temp2->next;
                delete temp2;
            }

            head = tail = nullptr;
            length = 0;
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