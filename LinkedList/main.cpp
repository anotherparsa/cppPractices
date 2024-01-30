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
                Node* temp = this->head;
                while (temp != nullptr){
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
                return ;
            }else{
                Node* temp = this->head;
                Node* previous = this->head;
                while (temp->next != nullptr){
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

        void prepend(int value){
            Node* newNode = new Node(value);
            if (this->head == nullptr || this->length == 0){
                this->head = newNode;
                this->tail = newNode;
            }else{
                newNode->next = this->head;
                this->head = newNode;
            }
            this->length += 1;
        }

        void deleteFirst(){
            if (this->head == nullptr || this->length == 0){
                return;
            }else{
                Node* temp = this->head;
                if (this->length == 1){
                    this->head = nullptr;
                    this->tail = nullptr;
                }else{
                    this->head = this->head->next;
                }
                delete temp;
                this->length -= 1;
            }
        }

        void get(int index){
            if (index < 0 || index >= this->length){
                cout << "Invalid Index" << endl;
            }else{
                Node* temp = this->head;
                for (int i = 0 ; i < index ; i++ ){
                    temp = temp->next;
                }
                if (temp != nullptr){
                    cout << "The value of Index " << index << " is " << temp->value << endl;
                }else{
                    cout << "Something went wrong" << endl;
                }
            }
        }

        void set(int index, int value){
            if (index < 0 || index >= this->length){
                cout << "Invalid Index" << endl;
            }else{
                Node* temp = head;
                for (int i = 0 ; i < index ; i++){
                    temp = temp->next;
                }
                if (temp != nullptr){
                    temp->value  = value;
                    cout << "Setting value of Index " << index << " was successfull" << endl;
                }else{
                    cout << "Something went wrong" << endl;
                }
            }
        }

        void insert(int index, int value){
            if (index < 0 || index > this->length){
                cout << "Invalid Index" << endl;
            }else if (index == 0){
                prepend(value);
                cout << "New Node has been added" << endl;
            }else if (index == this->length){
                append(value);
                cout << "New Node has been addded" << endl;
            }else{
                Node* newNode = new Node(value);
                Node* temp = head;
                for (int i = 0 ; i < index - 1 ; i++){
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;
                this->length += 1;
                cout << "New Node has been added" << endl;
            }
        }

        void deleteNode(int index){
            if (index < 0 || index >= this->length){
                cout << "Invalid Index" << endl;
            }else if (index == 0){
                deleteFirst();
                cout << "Node has been removed" << endl;
            }else if (index == this->length - 1){
                deleteLast();
                cout << "Node has been removed" << endl;
            }else{
                Node* previous = this->head;
                for (int i = 0 ; i < index - 1 ; i++){
                    previous = previous->next;
                }
                Node* temp = previous->next;
                previous->next = temp->next;
                delete temp;
                cout << "Node has been removed" << endl;
                this->length -= 1;
            }
        }
};

int main(){
    LinkedList* newLinkedList = new LinkedList();
    newLinkedList->getLength();
    newLinkedList->printList();
    newLinkedList->append(1);
    newLinkedList->getLength();
    newLinkedList->getHead();
    newLinkedList->getTail();
    newLinkedList->printList();
    newLinkedList->append(2);
    newLinkedList->getLength();
    newLinkedList->getHead();
    newLinkedList->getTail();
    newLinkedList->printList();
    newLinkedList->append(3);
    newLinkedList->getLength();
    newLinkedList->getHead();
    newLinkedList->getTail();
    newLinkedList->printList();
    newLinkedList->deleteLast();
    newLinkedList->getLength();
    newLinkedList->getHead();
    newLinkedList->getTail();
    newLinkedList->printList();
    newLinkedList->prepend(0);
    newLinkedList->getLength();
    newLinkedList->getHead();
    newLinkedList->getTail();
    newLinkedList->printList();
    newLinkedList->prepend(-1);
    newLinkedList->getLength();
    newLinkedList->getHead();
    newLinkedList->getTail();
    newLinkedList->printList();
    newLinkedList->prepend(-2);
    newLinkedList->getLength();
    newLinkedList->getHead();
    newLinkedList->getTail();
    newLinkedList->printList();
    newLinkedList->deleteFirst();
    newLinkedList->getLength();
    newLinkedList->getHead();
    newLinkedList->getTail();
    newLinkedList->get(0);
    newLinkedList->set(1,5);
    newLinkedList->getLength();
    newLinkedList->getHead();
    newLinkedList->getTail();
    newLinkedList->printList();
    newLinkedList->insert(1,-5);
    newLinkedList->getLength();
    newLinkedList->getHead();
    newLinkedList->getTail();
    newLinkedList->printList();
    newLinkedList->deleteNode(1);
    newLinkedList->getLength();
    newLinkedList->getHead();
    newLinkedList->getTail();
    newLinkedList->printList();
}