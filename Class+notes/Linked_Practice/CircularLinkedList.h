#ifndef CircularLinkedList_H
#define CircularLinkedList_H

#include <iostream>

class cll{
    private:
        struct node{
            node *next;
            int value;
        };
        node *last;
        int size;
    public:
        cll();
        void add(int x);
        void remove(int index);
        void display();
        int peekFirst();
        int peekLast();
        bool isEmpty();
        int getLength();
        friend std::ostream& operator<<(std::ostream &out,const cll& rhs);
        ~cll();
        cll(const cll&rhs);
        const cll& operator =(const cll&rhs);

};

cll::cll(){
    this->size=0;
    this->last=nullptr;
}

void cll::add(int x){
    node* tmp=new node{nullptr,x};
    if(isEmpty()){
        last=tmp;
        tmp->next=last;
        this->size+=1;
    }else{
        tmp->next=last->next;
        last->next=tmp;
        last=tmp;
        this->size+=1;
    }
}

void cll::remove(int index){
    if(this->isEmpty()){
        return;
    }
    if(index>=this->size-1){
        node* tmp=last;
        for(int i=0;i<this->size-1;i++){
            last=last->next;
        }
        last->next=tmp->next;
        this->size-=1;
        delete tmp;
    }else if(index<=0){
        node* tmp=last->next;
        last->next=tmp->next;
        this->size-=1;
        delete tmp;
    }else{
        node* rewire=last;
        for(int i=0;i<index;i++){
            rewire=rewire->next;
        }
        node*tmp=rewire->next;
        rewire->next=tmp->next;
        this->size-=1;
    }
    if(this->size==0){
        last=nullptr;
    }
}

void cll::display(){
    if(this->isEmpty()){
        std::cout<<"{EMPTY}\n";
        return;
    }
    node* temp=this->last->next;
    std::cout<<"{";
    while(temp!=last){
        std::cout<<temp->value<<",";
        temp=temp->next;
    }
    std::cout<<temp->value<<"}\n";
}

int cll::peekFirst(){
    return last->next->value;
}

int cll::peekLast(){
    return last->value;
}

bool cll::isEmpty(){
    return last==nullptr;
}

int cll::getLength(){
    return this->size;
}

std::ostream& operator<<(std::ostream &out,const cll& rhs){
    if(rhs.last==nullptr){
        out<<"{EMPTY}\n";
        return out;
    }else{
        cll::node* temp=rhs.last->next;
        out<<"{";
        while(temp!=rhs.last){
            out<<temp->value<<",";
            temp=temp->next;
        }
        out<<temp->value<<"}\n";
        return out;   
    }
    
}

cll::~cll(){
    node* head=last->next;
    last->next=nullptr;
    while(head){
        node* temp=head;
        head=head->next;
        delete temp;
    }
    std::cerr<<"DELETE\n";
}

cll::cll(const cll&rhs){
    this->last=nullptr;
    node* tmp=rhs.last->next;
    while(tmp!=rhs.last){
        this->add(tmp->value);
        tmp=tmp->next;
    }
    this->add(tmp->value);
    this->size=rhs.size;
    std::cerr<<"COPY\n";
}

const cll& cll::operator =(const cll&rhs){
    if(this==&rhs){
        return *this;
    }

    node* head=last->next;
    last->next=nullptr;
    while(head){
        node* temp=head;
        head=head->next;
        delete temp;
    }
    this->last=nullptr;
    node* tmp=rhs.last->next;
    while(tmp!=rhs.last){
        this->add(tmp->value);
        tmp=tmp->next;
    }
    this->add(tmp->value);
    this->size=rhs.size;
    std::cerr<<"ASSIGNMENT\n";
    return *this;
}

#endif