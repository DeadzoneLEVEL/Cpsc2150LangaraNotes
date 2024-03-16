#ifndef LinkedList_H
#define LinkedList_H

#include <iostream>

class ll{
    private:
        struct node{
            node *next;
            int value;
        };
        node *head;
        int size;
        node *reverse(node *rhs);
    public:
        ll();
        void add(int x);
        void remove(int index);
        int getFirst();
        int getLast();
        bool isEmpty();
        int getLength();
        void removeall();
        friend std::ostream& operator<<(std::ostream &out,const ll& rhs);
        ~ll();
        ll(const ll&rhs);
        const ll& operator =(const ll&rhs);

};

ll::node* ll::reverse(node *rhs){
    ll::node *temp=rhs;
    ll::node *result=nullptr;
    while(temp){
        result=new node{result,temp->value};
        temp=temp->next;
    }
    return result;
}

ll::ll(){
    this->size=0;
    this->head=nullptr;
}

void ll::add(int x){
    head=new node{head,x};
    this->size+=1;
}

void ll::remove(int index){
    if(index<=0){
        node *temp=this->head;
        head=head->next;
        delete temp;
        this->size-=1;
    }else{
        if(index>=this->size){
            index=this->size-1;
        }
        node *tmp=this->head;
        for(int i=0;i<index-1;i++){
            tmp=tmp->next;
        }
        node *temp=tmp->next;
        tmp->next=temp->next;
        delete temp;
        this->size-=1;
    } 
}

int ll::getFirst(){
    return head->value;
}

int ll::getLast(){
    node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    return temp->value;
}

bool ll::isEmpty(){
    return head==nullptr;
}

int ll::getLength(){
    return this->size;
}

void ll::removeall(){
    while(head){
        node* temp=head;
        head=head->next;
        delete temp;
    }
}

std::ostream& operator<<(std::ostream &out,const ll& rhs){
    ll::node *temp=rhs.head;
    out<<"{ ";
    while(temp){
        out<<temp->value<<" ";
        temp=temp->next;
    }
    out<<"}"<<std::endl;
    return out;    
}

ll::~ll(){
    while(head){
        node* temp=head;
        head=head->next;
        delete temp;
    }
    std::cerr<<"DELETE\n";
}

ll::ll(const ll&rhs){
    this->head=nullptr;
    this->size=rhs.size;
    node* temp=reverse(rhs.head);
    while(temp){
        head=new node{head,temp->value};
        temp=temp->next;
    }
    std::cerr<<"COPY\n";
}

const ll& ll::operator =(const ll&rhs){
    if(this==&rhs){
        return *this;
    }
    while(head){
        node* temp=head;
        head=head->next;
        delete temp;
    }
    this->head=nullptr;
    node *temp=reverse(rhs.head);
    while(temp){
        head=new node{head,temp->value};
        temp=temp->next;
    }
    this->size=rhs.size;
    std::cerr<<"ASSIGNMENT\n";
    return *this;
}

#endif