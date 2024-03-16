#include <iostream>

using namespace std;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Node {
public:
    int data;
    int id;
    Node* next;

    Node(int value,int str) : data(value),id(str), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* last;

public:
    CircularLinkedList() : last(nullptr) {}

    // Insert a new node with data at the end of the circular linked list
    void insert(int data,int id) {
        Node* new_node = new Node(data,id);
        if (!last) {
            last = new_node;
            last->next = last;
        } else {
            new_node->next = last->next;
            last->next = new_node;
            last = new_node;
        }
    }

    // Delete a node with the given data
    void deleteNode(int data) {
        if (!last)
            return;

        Node* current = last->next;
        Node* previous = nullptr;

        while (current->next != last->next) {
            if (current->data == data) {
                if (current == last->next)
                    last->next = last->next->next;
                if (current == last)
                    last = previous;
                if (previous)
                    previous->next = current->next;
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        }

        if (current->data == data) {
            if (current == last->next)
                last->next = last->next->next;
            if (current == last)
                last = previous;
            if (previous)
                previous->next = current->next;
            delete current;
        }
    }

    // Search for a node with the given data
    bool search(int data) {
        if (!last)
            return false;

        Node* current = last->next;

        do {
            if (current->data == data)
                return true;
            current = current->next;
        } while (current != last->next);

        return false;
    }
    bool isEmpty(){
        return last==nullptr;
    }

    Node* getPointer(){
        return last;
    }

    Node* getPrevPointer(){
        Node *current=last;
        while(current->next!=last){
            current=current->next;
        }
        return current;
    }

    // display all elements in the circular linked list
    void display() {
        if (!last)
            return;

        Node* current = last->next;

        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != last->next);

        cout << endl;
    }

    void deleteall(){
        Node* current=last->next;
        last->next=nullptr;
        while(current){
            Node* tmp=current;
            current=current->next;
            delete tmp;
        }
        last=nullptr;
    }

    void deleteNode(Node * todel){
        if (!last)
            return;

        Node* current = last->next;
        Node* previous = nullptr;
        if(current==current->next&&current==todel){
            this->deleteall();
            return;
        }

        while (current->next != last->next) {
            if (current == todel) {
                if (current == last->next)
                    last->next = last->next->next;
                if (current == last)
                    last = previous;
                if (previous)
                    previous->next = current->next;
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        }

        if (current == todel) {
            if (current == last->next)
                last->next = last->next->next;
            if (current == last)
                last = previous;
            if (previous)
                previous->next = current->next;
            delete current;
        }
    }

    ~CircularLinkedList(){
        Node* current=nullptr;
        if(last!=nullptr&&last->next!=last){
            current=last->next;
        }else{
            Node *tmp=last;
            delete tmp;
            last=nullptr;
            return;
        }
        last->next=nullptr;
        while(current){
            Node* tmp=current;
            current=current->next;
            delete tmp;
        }
        last=nullptr;
        std::cerr<<"DELETE\n";
    }
};

#endif