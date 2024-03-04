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

        bool is_list_empty(){
            return (this->head == nullptr && this->length == 0);
        }

        void get_head(){
            if (this->is_list_empty()){
                cout << "There are no Nodes in the list" << endl;
            }else{
                cout << "Head address " << this->head << " Head value :" << this->head->value << endl; 
            }
        }

        void get_tail(){
            if (this->is_list_empty()){
                cout << "There are no Nodes in the list" << endl;
            }else{
                cout << "Tail address " << this->tail << " Tail value : " << this->tail->value << endl;
            }
        }

        void get_length(){
            cout << "Length : " << this->length << endl;
        }

        void print_list(){
            if (this->is_list_empty()){
                cout << "There are no Nodes in the list" << endl;
            }else{
                Node* temp = this->head;
                while(temp != nullptr){
                    cout << temp->value << endl;
                    temp = temp->next;
                }
            }
        }

        void append_node(int value){
            Node* new_node = new Node(value);
            if (this->is_list_empty()){
                this->head = new_node;
                this->tail = new_node;
            }else{
                this->tail->next = new_node;
                this->tail = new_node;
            }
            this->length++;
            cout << "New Node has been added to the end of the list" << endl;
        }

        void delete_last_node(){
            if (this->is_list_empty()){
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

        void prepend_node(int value){
            Node* new_node = new Node(value);
            if (this->is_list_empty()){
                this->head = new_node;
                this->tail = new_node;
            }else{
                new_node->next = this->head;
                this->head = new_node;
            }
            this->length++;
            cout << "New Node has been added to the beginning of the list" << endl;
        }

        void delete_first_node(){
            if (this->is_list_empty()){
                cout << "There are no Nodes in the list" << endl;
            }else{
                Node* temp = this->head;
                if (this->length == 1){
                    this->head = nullptr;
                    this->tail = nullptr;
                }else{
                    this->head = this->head->next;
                }
                delete temp;
                this->length--;
                cout << "Node has been removed from the beginning of the list" << endl;
            }
        }

        Node* get_node(int index){
            if (this->is_list_empty()){
                cout << "There are no Nodes in the list" << endl;
                return nullptr;
            }else if (index < 0 || index >= this->length){
                cout << "Invalid index" << endl;
                return nullptr;
            }else{
                Node* temp = this->head;
                for (int i = 0 ; i < index ; i++){
                    temp = temp->next;
                }
                if (temp != nullptr){
                    return temp;
                }else{
                    cout << "Something went wrong" << endl;
                    return nullptr;;
                }
            }
        }

        void print_value(int index){
            if (this->is_list_empty()){
                cout << "There are no Nodes in the list" << endl;
            }else if (index < 0 || index >= this->length){
                cout << "Invalid index" << endl;
            }else{
                Node* temp = this->get_node(index);
                cout << "The value of Node at index " << index << " is " << temp->value << endl;
            }
        }

        void set_value(int index, int value){
            if (this->is_list_empty()){
                cout << "There are no Nodes in the list" << endl;
            }else if (index < 0 || index >= this->length){
                cout << "Invalid index" << endl;
            }else{
                Node* temp = this->get_node(index);
                cout << "The value of Node at index " << index << " was " << temp->value;
                temp->value = value;
                cout << " Now it's " << value << endl;
            }
        }

        void insert_node(int index, int value){
            if (this->is_list_empty()){
                cout << "There are no Nodes in the list" << endl;
            }else if (index < 0 || index > this->length){
                cout << "Invalid index" << endl;
            }else if (index == 0){
                this->prepend_node(value);
            }else if (index == this->length - 1){
                this->append_node(value);
            }else{
                Node* new_node = new Node(value);
                Node* temp = this->get_node(index - 1);
                new_node->next = temp->next;
                temp->next = new_node;
                this->length++;
                cout << "New Node with the value of " << value << " Has been added at index " << index << " To the list" <<endl;
            }
        }

        void delete_node(int index){
            if (this->is_list_empty()){
                cout << "There are no Nodes in the list" << endl;
            }else if (index < 0 || index >= this->length){
                cout << "Invalid index" << endl;
            }else if (index == 0){
                this->delete_first_node();
            }else if (index == this->length - 1){
                this->delete_last_node();
            }else{
                Node* previous = this->get_node(index - 1);
                Node* temp = this->get_node(index);
                previous->next = temp->next;
                cout << "Node with the value of " << temp->value << " at index " << index << " Has been removed from the list" << endl;
                delete temp;
                this->length--;
            }
        }

        void pop_node(){
            if (this->is_list_empty()){
                cout << "There are no Nodes" << endl;
            }else{
                Node* previous = this->get_node(this->length - 2);
                Node* temp = this->tail;
                this->tail = previous;
                this->tail->next = nullptr;
                this->length--;
                cout << "Node with the value of " << temp->value << " Has popped out of the list" << endl;
                delete temp;
            }

        }
};

int main(){
    LinkedList* MyLinkedList = new LinkedList();
    MyLinkedList->print_list();
    MyLinkedList->get_head();
    MyLinkedList->get_tail();
    MyLinkedList->get_length();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->append_node(1);
    MyLinkedList->print_list();
    MyLinkedList->get_head();
    MyLinkedList->get_tail();
    MyLinkedList->get_length();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->append_node(2);
    MyLinkedList->print_list();
    MyLinkedList->get_head();
    MyLinkedList->get_tail();
    MyLinkedList->get_length();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->append_node(3);
    MyLinkedList->print_list();
    MyLinkedList->get_head();
    MyLinkedList->get_tail();
    MyLinkedList->get_length();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->append_node(4);
    MyLinkedList->print_list();
    MyLinkedList->get_head();
    MyLinkedList->get_tail();
    MyLinkedList->get_length();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->delete_last_node();
    MyLinkedList->print_list();
    MyLinkedList->get_head();
    MyLinkedList->get_tail();
    MyLinkedList->get_length();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->append_node(5);
    MyLinkedList->print_list();
    MyLinkedList->get_head();
    MyLinkedList->get_tail();
    MyLinkedList->get_length();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->delete_last_node();
    MyLinkedList->print_list();
    MyLinkedList->get_head();
    MyLinkedList->get_tail();
    MyLinkedList->get_length();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->delete_last_node();
    MyLinkedList->print_list();
    MyLinkedList->get_head();
    MyLinkedList->get_tail();
    MyLinkedList->get_length();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->prepend_node(-1);
    MyLinkedList->print_list();
    MyLinkedList->get_head();
    MyLinkedList->get_tail();
    MyLinkedList->get_length();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->prepend_node(-2);
    MyLinkedList->print_list();
    MyLinkedList->get_head();
    MyLinkedList->get_tail();
    MyLinkedList->get_length();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->prepend_node(-3);
    MyLinkedList->print_list();
    MyLinkedList->get_head();
    MyLinkedList->get_tail();
    MyLinkedList->get_length();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->delete_first_node();
    MyLinkedList->print_list();
    MyLinkedList->get_head();
    MyLinkedList->get_tail();
    MyLinkedList->get_length();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->prepend_node(-4);
    MyLinkedList->print_list();
    MyLinkedList->get_head();
    MyLinkedList->get_tail();
    MyLinkedList->get_length();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->delete_first_node();
    MyLinkedList->print_list();
    MyLinkedList->get_head();
    MyLinkedList->get_tail();
    MyLinkedList->get_length();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->delete_first_node();
    MyLinkedList->print_list();
    MyLinkedList->get_head();
    MyLinkedList->get_tail();
    MyLinkedList->get_length();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->print_value(0);
    cout << "-------------------------------------------" << endl;
    MyLinkedList->print_value(2);
    cout << "-------------------------------------------" << endl;
    MyLinkedList->print_value(1);
    cout << "-------------------------------------------" << endl;
    MyLinkedList->print_value(10);
    cout << "-------------------------------------------" << endl;
    MyLinkedList->set_value(0, 100);
    cout << "-------------------------------------------" << endl;
    MyLinkedList->set_value(50, 100);
    cout << "-------------------------------------------" << endl;
    MyLinkedList->set_value(1, 200);
    cout << "-------------------------------------------" << endl;
    MyLinkedList->set_value(3, 300);
    cout << "-------------------------------------------" << endl;
    MyLinkedList->insert_node(1, 500);
    MyLinkedList->print_list();
    MyLinkedList->get_head();
    MyLinkedList->get_tail();
    MyLinkedList->get_length();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->insert_node(0, 600);
    MyLinkedList->print_list();
    MyLinkedList->get_head();
    MyLinkedList->get_tail();
    MyLinkedList->get_length();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->insert_node(2, 400);
    MyLinkedList->print_list();
    MyLinkedList->get_head();
    MyLinkedList->get_tail();
    MyLinkedList->get_length();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->delete_node(0);
    MyLinkedList->print_list();
    MyLinkedList->get_head();
    MyLinkedList->get_tail();
    MyLinkedList->get_length();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->prepend_node(700);
    MyLinkedList->print_list();
    MyLinkedList->get_head();
    MyLinkedList->get_tail();
    MyLinkedList->get_length();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->prepend_node(800);
    MyLinkedList->print_list();
    MyLinkedList->get_head();
    MyLinkedList->get_tail();
    MyLinkedList->get_length();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->delete_node(1);
    MyLinkedList->print_list();
    MyLinkedList->get_head();
    MyLinkedList->get_tail();
    MyLinkedList->get_length();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->delete_node(2);
    MyLinkedList->print_list();
    MyLinkedList->get_head();
    MyLinkedList->get_tail();
    MyLinkedList->get_length();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->pop_node();
    MyLinkedList->print_list();
    MyLinkedList->get_head();
    MyLinkedList->get_tail();
    MyLinkedList->get_length();
    cout << "-------------------------------------------" << endl;
    MyLinkedList->pop_node();
    MyLinkedList->print_list();
    MyLinkedList->get_head();
    MyLinkedList->get_tail();
    MyLinkedList->get_length();
    cout << "-------------------------------------------" << endl;
}