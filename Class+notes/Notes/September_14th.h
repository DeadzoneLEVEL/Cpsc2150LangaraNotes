#ifndef SEPTEMBER_14TH_H
#define SEPTEMBER_14TH_H
#include <iostream>
#include <vector>

class ss{
    public:
        ss();
        int peek();
        void push(int x);
        int pop();
        bool isEmpty();
        int length();
        void print();

        ~ss();
        ss(ss &rhs);
        const ss& operator=(ss &rhs);
    private:
        std::vector<int> data;
        int size;
};

ss::ss(){
    this->size=0;
}

int ss::peek(){
    if(this->isEmpty()){
        std::cerr<<"No element found";
        return 0;
    }
    int num=this->data[this->size-1];
    return num;
}

void ss::push(int x){
    this->data.push_back(x);
    this->size+=1;
}

int ss::pop(){
    if(this->isEmpty()){
        std::cerr<<"No element found";
        return 0;
    }
    int num=this->data[this->size-1];
    this->data.pop_back();
    this->size-=1;
    return num;
}

bool ss::isEmpty(){
    return this->size==0;
}

int ss::length(){
    return this->size;
}

void ss::print(){
    std::cout<<"{ ";
    for(int i=0;i<this->size;i++){
        std::cout<<this->data[i]<<" ";
    }
    std::cout<<"}\n";
}

ss::~ss(){
    this->data.clear();
    this->size=0;
    std::cerr<<"DELETE\n";
}

ss::ss(ss &rhs){
    this->size=rhs.length();
    for(int i=0;i<rhs.length();i++){
        this->data.push_back(rhs.data[i]);
    }
    std::cerr<<"COPY\n";
}

const ss& ss::operator=(ss &rhs){
    if(this==&rhs){
        return *this;
    }
    this->data.clear();
    this->size=rhs.length();
    for(int i=0;i<rhs.length();i++){
        this->data.push_back(rhs.data[i]);
    }
    std::cerr<<"ASSIGNMENT\n";
    return *this;
}

#endif