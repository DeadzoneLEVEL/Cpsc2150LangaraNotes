#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "LinkedListFull.h"

class queue{
    public:
        queue(int);
        int dequeue();
        void enqueue(int);
        int front();
        bool is_empty();
       
        // do big three memory stuff
    private:
    struct node{
        int data;
        node *next;
    };
    node* head,*tail;




};

queue::queue(int x){
   head=tail=nullptr;
}

int queue::dequeue(){
    if(is_empty()){
        std::cout<<"Empty queue";
        exit(1);
    }
    int ret=head->data;
    node* todel=head;
    head=head->next;
    delete[]todel;
    if(!head){
        tail=head;
    }
    return ret;
}

void queue::enqueue(int x){
    if(is_empty()){
        head=new node{x,nullptr};
        tail=head;
    }else{
        tail->next=new node{x,nullptr};
        tail=tail->next;
    }
    
}

int queue::front(){
    if(is_empty()){
        exit(1);
    }
    return head->data;
}

bool queue::is_empty(){
    return !head&&!tail;
}



#endif