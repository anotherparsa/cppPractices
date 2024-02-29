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

        bool isListEmpty(){
            return (this->length == 0 || this->head == nullptr);
        }

        void getHead(){
            if (this->isListEmpty()){
                cout << "There are no Node in the list" << endl;
            }else{
                cout << "Head address: " << this->head << " Head value: " << this->head->value << endl;
            }
        }

        void getTail(){
            if (this->isListEmpty()){
                cout << "There are no Nodes in the list" << endl;
            }else{
                cout << "Tail address: " << this->tail << " Tail value: " << this->tail->value << endl;
            }
        }

        void getLength(){
            cout << "Length: " << this->length << endl;
        }

        void printList(){
            if (this->isListEmpty()){
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
            if (this->isListEmpty()){
                this->head = newNode;
                this->tail = newNode;
            }else{
                this->tail->next = newNode;
                this->tail = newNode;
            }
            this->length++;
            cout << "New Node has been added to the end of the list" << endl;
        }

        void deleteLast(){
            if(this->isListEmpty()){
                cout << "There are no Nodes in the list" << endl;
            }else{
                Node* temp = this->head;
                Node* previous = this->head;
                while(temp->next != nullptr){
                    previous = temp;
                    temp = temp->next;
                }
                this->tail = previous;
                this->tail->next = nullptr;
                this->length--;
                if (this->length == 0){
                    this->head = nullptr;
                    this->tail = nullptr;
                }
                delete temp;
                cout << "Node has been removed from the end of the list" << endl;
            }
        }

        void prepend(int value){
            Node* newNode = new Node(value);
            if(this->isListEmpty()){
                this->head = newNode;
                this->tail = newNode;
            }else{
                newNode->next = this->head;
                this->head = newNode;
            }
            this->length++;
            cout << "New Node has been added to the beginning of the list" << endl;
        }

        void deleteFirst(){
            if (this->isListEmpty()){
                cout << "There are no Nodes in the list" << endl;
            }else{
                Node* temp = this->head;
                if (this->length == 1){
                    this->head = nullptr;
                    this->tail = nullptr;
                }else{
                    this->head = this->head->next;
                }
                this->length--;
                delete temp;
                cout << "Node has been removed from the beginning of the list" << endl;
            }
        }

        Node* getNode(int index){
            if (this->isListEmpty()){
                cout << "There are no Nodes in the list" << endl;
                return nullptr;
            }else if (index < 0 || index >= this->length){
                cout << "Invalid index" << endl;
            }else{
                Node* temp = this->head;
                for (int i = 0 ; i < index ; i++){
                    temp = temp->next;
                }  
                if (temp != nullptr){
                    return temp;
                }else{
                    cout << "Something went wrong" << endl;
                }
            }
            return nullptr;
        }

        void getValue(int index){
            if (this->isListEmpty()){
                cout << "There are no Nodes in the list" << endl;
            }else if (index < 0 || index >= this->length){
                cout << "Invalid index" << endl;
            }else{
                Node* temp = this->getNode(index);
                cout << "The value of Node at index " << index << " is " << temp->value << endl;
            }
        }

        void set(int index, int value){
            if (this->isListEmpty()){
                cout << "There are no Nodes in the list" << endl;
            }else if (index < 0 || index >= this->length){
                cout << "Invalid index" << endl;
            }else{
                Node* temp = getNode(index);
                cout << "The value of Node at index " << index << " Was " << temp->value;
                temp->value = value;
                cout << " Now it's " << temp->value << endl;
            }
        }

        void insert(int index, int value){
            if (index < 0 || index > this->length){
                cout << "Invalid index" << endl;
            }else if (index == 0){
                this->prepend(value);
            }else if (index == this->length){
                this->append(value);
            }else{
                Node* newNode = new Node(value);
                Node* temp = getNode(index - 1);
                newNode->next = temp->next;
                temp->next = newNode;
                this->length++;
                cout << "New Node with the value " << value << " Has been added at index " << index << endl;
            }
        }

        void deleteNode(int index){
            if (index < 0 || index > this->length){
                cout << "Invalid index" << endl;
            }else if (index == 0){
                this->deleteFirst();
            }else if (index == this->length - 1){
                this->deleteLast();
            }else{
                Node* previous = getNode(index - 1);
                Node* temp = getNode(index);
                previous->next = temp->next;
                delete temp;
                this->length--;
                cout << "Node at index " << index << " Has been removed" << endl;
            }
        }

        void pop(){
            Node* temp = this->getNode(this->length-1);
            cout << "Node with the value of " << temp->value << " Has popped out" << endl;
            this->deleteLast();
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
    MyLinkedList->append(3);
    MyLinkedList->printList();
    MyLinkedList->getHead();
    MyLinkedList->getTail();
    MyLinkedList->getLength();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->append(4);
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
    MyLinkedList->append(5);
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
    MyLinkedList->deleteLast();
    MyLinkedList->printList();
    MyLinkedList->getHead();
    MyLinkedList->getTail();
    MyLinkedList->getLength();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->prepend(-1);
    MyLinkedList->printList();
    MyLinkedList->getHead();
    MyLinkedList->getTail();
    MyLinkedList->getLength();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->prepend(-2);
    MyLinkedList->printList();
    MyLinkedList->getHead();
    MyLinkedList->getTail();
    MyLinkedList->getLength();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->prepend(-3);
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
    MyLinkedList->prepend(-4);
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
    MyLinkedList->deleteFirst();
    MyLinkedList->printList();
    MyLinkedList->getHead();
    MyLinkedList->getTail();
    MyLinkedList->getLength();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->getValue(0);
    cout << "-------------------------------------------" << endl;
    MyLinkedList->getValue(2);
    cout << "-------------------------------------------" << endl;
    MyLinkedList->getValue(1);
    cout << "-------------------------------------------" << endl;
    MyLinkedList->getValue(10);
    cout << "-------------------------------------------" << endl;
    MyLinkedList->set(0, 100);
    cout << "-------------------------------------------" << endl;
    MyLinkedList->set(50, 100);
    cout << "-------------------------------------------" << endl;
    MyLinkedList->set(1, 200);
    cout << "-------------------------------------------" << endl;
    MyLinkedList->set(3, 300);
    cout << "-------------------------------------------" << endl;
    MyLinkedList->insert(1, 500);
    MyLinkedList->printList();
    MyLinkedList->getHead();
    MyLinkedList->getTail();
    MyLinkedList->getLength();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->insert(0, 600);
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
    MyLinkedList->deleteNode(0);
    MyLinkedList->printList();
    MyLinkedList->getHead();
    MyLinkedList->getTail();
    MyLinkedList->getLength();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->prepend(700);
    MyLinkedList->printList();
    MyLinkedList->getHead();
    MyLinkedList->getTail();
    MyLinkedList->getLength();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->prepend(800);
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
    MyLinkedList->pop();
    MyLinkedList->printList();
    MyLinkedList->getHead();
    MyLinkedList->getTail();
    MyLinkedList->getLength();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->pop();
    MyLinkedList->printList();
    MyLinkedList->getHead();
    MyLinkedList->getTail();
    MyLinkedList->getLength();
    cout << "-------------------------------------------" << endl;
}