#include <iostream>

using namespace std;

class Node{
    public:
        int value;
        Node* next;

        Node(int value){
            this->value = value;
            this->next = nullptr;
        }
};

class LinkedList{
    private:
        Node* head;
        Node* tail;
        int length;
    
    public:
        LinkedList(){
            this->head = nullptr;
            this->tail = nullptr;
            this->length = 0;
        }

        void getHead(){
            cout << "Head: " << this->head << endl;
        }

        void getTail(){
            cout << "Tail: " << this->tail << endl;
        }

        void getLength(){
            cout << "Length: " << this->length << endl;
        }

        void printList(){
            if (this->head == nullptr || this->length == 0){
                cout << "There are no nodes in the list yet, try adding with append" << endl;
            }else{
                Node* temp = head;
                while(temp != nullptr){
                    cout << temp->value << endl;
                    temp = temp->next;
                }
            }
        }

        void append(int value){
            Node* newNode = new Node(value);
            if (this->head == nullptr || this->length == 0){
                this->head = newNode;
                this->tail = newNode;
            }else{
                this->tail->next = newNode;
                this->tail = newNode;
            }
            this->length += 1;
        }

        void deleteLast(){
            if (this->head == nullptr || this->length == 0){
                return;
            }else{
                Node* temp = head;
                Node* previous = head;
                while(temp->next != nullptr){
                    previous = temp;
                    temp = temp->next;
                }
                this->tail = previous;
                this->tail->next = nullptr;
                this->length -= 1;
                
                if (this->length == 0){
                    this->head = nullptr;
                    this->tail = nullptr;
                }
                delete temp;
            }
        }
}