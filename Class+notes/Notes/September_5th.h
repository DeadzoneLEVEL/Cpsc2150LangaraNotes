#ifndef SEPTEMBER_5TH_H
#define SEPTEMBER_5TH_H
#include<iostream>
#include <cmath>

class ll{
    public:
        ll();
        ~ll();
        ll(const ll&);
        ll operator =(const ll&);
    private:
        struct node{
            node *next;
            int data;
        };
        node *head;
};

    ll::ll(){
        this->head=nullptr;
    }
    ll::~ll(){
        node *temp;
        while(this->head){
            temp=this->head;
            this->head=this->head->next;
            delete temp;
        }
    }
    ll::ll(const ll&rhs){
        this->head=nullptr;
        
    }
#endif