#ifndef STACK_H
#define STACK_H
#include "LinkedList.h"

class ss{
    private:
        ll arr;
        int size;
    public:
        ss();
        int peek();
        void push(int x);
        int pop();
        bool isEmpty();
        int length();
        void display();

        ~ss();
        ss(ss &rhs);
        const ss& operator=(ss &rhs);
};

ss::ss(){
    size=0;
}

int ss::peek(){
    if(arr.isEmpty()){
        std::cerr<<"ERROR: stack is empty";
        return 0;
    }else{
        int ret=arr.getLast();
        return ret;
    }
}

void ss::push(int x){
    arr.add(x);
    size+=1;
}

int ss::pop(){
    int ret=arr.getLast();
    arr.remove(size-1);
    size-=1;
    return ret;
}

bool ss::isEmpty(){
    return arr.isEmpty();
}

int ss::length(){
    return size;
}

void ss::display(){
    std::cout<<arr;
}

ss::~ss(){
    arr.removeall();
    size=0;
    std::cerr<<"DELETE\n";    
}

ss::ss(ss &rhs){
    ss temp;
    this->arr.removeall();
    this->size=0;
    while(!rhs.isEmpty()){
        int tmp=rhs.pop();
        temp.push(tmp);
    }
    while(!temp.isEmpty()){
        int tmp=temp.pop();
        rhs.push(tmp);
        this->push(tmp);
    }
    std::cerr<<"COPY\n";
}

const ss& ss::operator=(ss &rhs){
    if(this==&rhs){
        return *this;
    }
    arr.removeall();
    size=0;
    ss temp;
    this->arr.removeall();
    this->size=0;
    while(!rhs.isEmpty()){
        int tmp=rhs.pop();
        temp.push(tmp);
    }
    while(!temp.isEmpty()){
        int tmp=temp.pop();
        rhs.push(tmp);
        this->push(tmp);
    }
    std::cerr<<"ASSIGNMENT\n";
    return *this;
}
#endif