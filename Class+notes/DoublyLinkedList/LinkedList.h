#include "Node.h"
#include <iostream>

using namespace std;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList{
public:
    Node* head;
    Node* tail;

    LinkedList(){
        // empty list
        head = nullptr;
        tail = nullptr;
    }

    LinkedList(int n){
        head = tail = nullptr;
        for(int i = 0; i < n; i++){
            AddNodeLast(i + 1);
        }
    }

    LinkedList(const LinkedList& source){
        head = tail = nullptr;

        Node* temp = source.head;
        while(temp != nullptr){
            AddNodeLast(temp->element);            
            temp = temp->next;
        }

    }

    ~LinkedList(){

        Node* temp;
        Node* nextNode = nullptr;

        for(temp = head; temp != tail; temp = nextNode){
            
            if(temp != nullptr){
                nextNode = temp->next;
                delete temp;
            }
        }

        delete tail;
        head = tail = nullptr;
    }

    bool IsEmpty(){
        return tail == nullptr;
    }

    int Size() const{
        int count = 0;
        Node* temp = tail;

        while(temp != nullptr){
            count++;
            temp = temp->prev;
        }

        return count;
    }

    void AddNodeLast(int value = 0){
        // add a new node to the end to the end of the list
        if(IsEmpty()){
            head = new Node(value);
            tail = head;
        }else{
            Node* temp = new Node(value);

            tail->next = temp;
            temp->prev = tail;

            tail = temp;
        }    
    }

    void ShowReverse(){
        Node* temp = tail;

        while(temp != nullptr){
            cout << temp->element << " - ";
            temp = temp->prev;
        }  
        cout << endl;      
    }

    void ShowForward(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->element << " - ";
            temp = temp->next;
        }  
        cout << endl;      
    }

    void AddNodeFirst(int value = 0){
        // add a new node at the beginning of the list i.e. new node will become the new head
        if(IsEmpty()){
            head = new Node(value);
            tail = head;
        }
        else{
            head->prev = new Node(value);
            head->prev->next = head;
            head = head->prev;
        }
    }
    
    void AddNodeFirstStudent(int value=0){
         if(IsEmpty()){
            head = new Node(value);
            tail = head;
        }else{
            Node* temp = new Node(value);
            head->prev = temp;
            temp->next = head;
            temp->prev = nullptr;

            head = temp;
        }
    }

    void AddNode(int index, int nodeValue){
        // O(n)

        // add a new node at position index containing nodeValue
        int sz = Size();
        if(index == 0){
            AddNodeFirst(nodeValue);
        }
        else if(index == sz - 1){
            AddNodeLast(nodeValue);
        }
        else if(index < sz && !(index < 0)){
            // find the item currently at index first
            Node* temp = head;
            for(int i = 0; i < index; i++){
                temp = temp->next;
            }

            //cout << temp->element << endl;
            Node* oldPrev = temp->prev;
            Node* newNode = new Node(nodeValue);
            temp->prev->next = newNode;
            temp->prev = newNode;
            newNode->next = temp;
            newNode->prev = oldPrev;
        }
        else{
            cout << "Index out of bounds" << endl;
        }

        
    }

    void RemoveFirst(){
        // remove the head node
    }

    void RemoveLast(){
        // remove the tail node
    }

    int Remove(int index){
        // remove node at given index and return the value removed
    }

    void Swap(int index1, int index2){
        // validate indices first
        // swap nodes at indices index1 and index2
        // Rewire connections (prev and next links) to swap
        // do NOT use a temporary variable to swap // this requirement is stupid, ignore it

    }

    int firstIndexOf(int item){
        // search for the first index of item within the list
        // if not found return -1
        // head is node with index 0
        if(IsEmpty()){
            cout << "The list is empty" << endl;
            return -1;
        }
        return firstIndexOf(item, head, 0);
    }

    int firstIndexOf(int item, Node* temp, int index){
        // recursive method that returns the first index
    }

};

#endif