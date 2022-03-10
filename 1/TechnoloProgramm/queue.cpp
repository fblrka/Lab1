#include "queue.h"
#include <iostream>

using namespace std;


List::List() {
    
        head = nullptr;
        size = 0;
    
}

List::~List() {
    
    while (size != 0) {
        
        Node* temp = head;
        head = temp->pNext;
        delete temp;
        size--;
    
    }
}

void List::Push_Back(int value) {

    if (head == nullptr)
        head = new Node(value);
    else {
        
        Node* current = this->head;

        while (current->pNext != nullptr) {
           
            current = current->pNext;
        
        }
        
        current->pNext = new Node(value);
    }
    size++;
}


int& List::operator[](const int index) {

    int counter = 0;
    Node* current = this->head;

    while (current->pNext != nullptr) {
        
        if (counter == index) return current->data;
        
        current = current->pNext;
        counter++;
    
    }
}


void List::Pop_Front() {
    
    Node* temp = head;
    head = head->pNext;
    delete temp;
    size--;

}

void List::SearchMax(List& obj) {

    Node* current = this->head;
   
    if (this->head == nullptr) {
        cout << "Очередь пуста, задание невыполнимо." << endl;
        system("pause");
        return;
    }
    int MAX = this->head->data;

    while (current != nullptr) {

        if (current->data > MAX) {
            
            MAX = current->data;
            
        }
            
        current = current->pNext;
    
    }

    cout << MAX << endl << endl;

}

void List::Copying( List& obj) {

    int temp[100];
    Node* current = obj.head;

    for (int i = 0; i < obj.size; i++) {

        temp[i] = current->data;
        current = current->pNext;

    }

    for (int i = 0; i < obj.size; i++) {

        Push_Back(temp[i]);

    }
}

void List::Merge( List& obj, const List& obj2) {
    
    int temp[100], temp2[100];
    Node* current = obj.head;

    for (int i = 0; i < obj.size; i++) {

        temp[i] = current->data;
        current = current->pNext;

    }

    int lenght = obj2.size + obj.size;
    Node* current2 = obj2.head;

    for (int i = obj.size; i < lenght; i++) {

        temp[i] = current2->data;
        current2 = current2->pNext;

    }
    
    for (int i = 0; i < lenght; i++) {

        Push_Back(temp[i]);

    }
}
