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

        bool isEmpty(){
            return (this->head == nullptr || this->length == 0);
        }

        void getHead(){
            if (isEmpty()){
                cout << "There are no Nodes in the list" << endl;
            }else{
                cout << "Head address: " << this->head << " Head value: " << this->head->value << endl;
            }
        }

        void getTail(){
            if (isEmpty()){
                cout << "There are no Nodes in the list" << endl;
            }else{
                cout << "Tail address: " << this->tail << " Tail value: " << this->tail->value << endl;
            }
        }

        void getLength(){
            cout << "Length: " << this->length << endl;
        }

        void printList(){
            if (isEmpty()){
                cout << "There are no Nodes in the list" << endl;
            }else{
                Node* temp = this->head;
                while(temp != nullptr){
                    cout << temp->value << endl;
                    temp = temp->next;
                }
            }
        }

        void append(int value){
            Node* newNode = new Node(value);
            if (isEmpty()){
                this->head = newNode;
                this->tail = newNode;
            }else{
                this->tail->next = newNode;
                this->tail = newNode;
            }
            this->length += 1;
            cout << "Node has been added to the end of the list " << endl;
        }

        void deleteLast(){
            if (isEmpty()){
                cout << "There are no Nodes in the list" << endl;
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
                cout << "Node has been removed from the end of the list " << endl;
            }
        }

        void prepend(int value){
            Node* newNode = new Node(value);
            if (isEmpty()){
                this->head = nullptr;
                this->tail = nullptr;
            }else{
                newNode->next = this->head;
                this->head = newNode;
            }
            this->length += 1;
            cout << "New Node has been added to the first of the list " << endl;
        }

        void deleteFirst(){
            if (isEmpty()){
                cout << "There are no Nodes in the list" << endl;
            }else{
                Node* temp = this->head;
                if (this->length == 0){
                    this->head = nullptr;
                    this->tail = nullptr;
                }else{
                    this->head = this->head->next;
                }
                delete temp;
                this->length -= 1;
                cout << "Node has been removed from the end of the list" << endl;
            }
        }

        void get(int index){
            if (index < 0 || index >= this->length){
                cout << "Invalid index" << endl;
            }else{
                Node* temp = this->head;
                for (int i = 0 ; i < index ; i++){
                    temp = temp->next;
                }
                if (temp != nullptr){
                    cout << "The value of Node in index " << index << " is " << temp->value << endl;
                }else{
                    cout << "Something went wrong" << endl;
                }
            }
        }

        void set(int index, int value){
            if (index < 0 || index >= this->length){
                cout << "Invalid index" << endl;
            }else{
                Node* temp = this->head;
                for (int i = 0 ; i < index ; i++){
                    temp = temp->next;
                }
                if (temp != nullptr){
                    cout << "The value of Node in index " << index << " was " << temp->value ;
                    temp->value = value;
                    cout << " Now it's " << temp->value << endl;
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
            }else if (index == this->length -1 ){
                append(value);
            }else{
                Node* newNode = new Node(value);
                Node* temp = this->head;
                for (int i = 0 ; i < index - 1; i++){
                    temp = temp->next;
                }
                if (temp != nullptr){
                    newNode->next = temp->next;
                    temp->next = newNode;
                }else{
                    cout << "Something went wrong" << endl;
                }
                this->length += 1;
                cout << "New Node with the value of " << value << " Has been added at index " << index << endl;
            }
        }

        void deleteNode(int index){
            if (index < 0 || index >= this->length){
                cout << "Invalid index" << endl;
            }else if (index == 0){
                deleteFirst();
            }else if (index = this->length - 1){
                deleteLast();
            }else{
                Node* temp = this->head;
                Node* previous = this->head;
                for (int i = 0 ; i < index ; i++){
                    previous = temp;
                    temp = temp->next;
                }
                if (previous != nullptr){
                    previous->next = temp->next;
                }
                this->length -= 1;
                cout << "Node in the index of " << index << " with the value of " << temp->value << " has been removed" << endl;
                delete temp;
            }
        }
};

int main(){
    LinkedList* MyLinkedList = new LinkedList();
    MyLinkedList->printList();
    MyLinkedList->getHead();
    MyLinkedList->getTail();
    MyLinkedList->getLength();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->append(1);
    MyLinkedList->printList();
    MyLinkedList->getHead();
    MyLinkedList->getTail();
    MyLinkedList->getLength();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->append(2);
    MyLinkedList->printList();
    MyLinkedList->getHead();
    MyLinkedList->getTail();
    MyLinkedList->getLength();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->deleteLast();
    MyLinkedList->printList();
    MyLinkedList->getHead();
    MyLinkedList->getTail();
    MyLinkedList->getLength();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->prepend(5);
    MyLinkedList->printList();
    MyLinkedList->getHead();
    MyLinkedList->getTail();
    MyLinkedList->getLength();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->prepend(10);
    MyLinkedList->printList();
    MyLinkedList->getHead();
    MyLinkedList->getTail();
    MyLinkedList->getLength();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->deleteFirst();
    MyLinkedList->printList();
    MyLinkedList->getHead();
    MyLinkedList->getTail();
    MyLinkedList->getLength();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->get(0);
    MyLinkedList->get(1);
    MyLinkedList->get(4);
    cout << "-------------------------------------------" << endl;
    MyLinkedList->set(0, 6);
    MyLinkedList->printList();
    MyLinkedList->getHead();
    MyLinkedList->getTail();
    MyLinkedList->getLength();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->set(3, 2);
    MyLinkedList->printList();
    MyLinkedList->getHead();
    MyLinkedList->getTail();
    MyLinkedList->getLength();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->insert(2, 10);
    MyLinkedList->printList();
    MyLinkedList->getHead();
    MyLinkedList->getTail();
    MyLinkedList->getLength();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->insert(1, 300);
    MyLinkedList->printList();
    MyLinkedList->getHead();
    MyLinkedList->getTail();
    MyLinkedList->getLength();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->insert(2, 400);
    MyLinkedList->printList();
    MyLinkedList->getHead();
    MyLinkedList->getTail();
    MyLinkedList->getLength();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->deleteNode(1);
    MyLinkedList->printList();
    MyLinkedList->getHead();
    MyLinkedList->getTail();
    MyLinkedList->getLength();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->deleteNode(2);
    MyLinkedList->printList();
    MyLinkedList->getHead();
    MyLinkedList->getTail();
    MyLinkedList->getLength();
    cout << "-------------------------------------------" << endl;
}
