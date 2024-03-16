#ifndef DoublyLinkedList_H
#define DoublyLinkedList_H

#include <iostream>

class dll{
    private:
        struct node{
            node *next;
            node *prev;
            int value;
        };
        node *head;
        node *tail;
        int size;
    public:
        dll();
        void addFirst(int x);
        void addLast(int x);
        void remove(int index);
        void displayForwards();
        void displayBackwards();
        int getFirst();
        int getLast();
        bool isEmpty();
        int getLength();
        friend std::ostream& operator<<(std::ostream &out,const dll& rhs);
        ~dll();
        dll(const dll&rhs);
        const dll& operator =(const dll&rhs);

};

dll::dll(){
    this->size=0;
    this->head=this->tail=nullptr;
}

void dll::addFirst(int x){
    if(isEmpty()){
        tail=head=new node{head,head,x};
        this->size+=1;
    }else{
        head=new node{head,nullptr,x};
        head->next->prev=head;
        this->size+=1;
    }
}

void dll::addLast(int x){
    if(isEmpty()){
        tail=head=new node{head,head,x};
        this->size+=1;
    }else{
        tail=new node{nullptr,tail,x};
        tail->prev->next=tail;
        this->size+=1;
    }
}

void dll::remove(int index){
    if(index<=0){
        node *temp=this->head;
        head=head->next;
        head->prev=nullptr;
        delete temp;
        this->size-=1;
    }else if(index>=this->size){
        node *temp=this->tail;
        tail=tail->prev;
        tail->next=nullptr;
        delete temp;
        this->size-=1;
    }else{
        int midpoint=this->size/2;
        if(index>midpoint){
            node *tmp=this->tail;
            for(int i=this->size-1;i>index+1;i--){
                tmp=tmp->prev;
            }
            node *temp=tmp->prev;
            tmp->prev=temp->prev;
            tmp->prev->next=tmp;
            delete temp;
            this->size-=1;
        }else{
            node *tmp=this->head;
            for(int i=0;i<index-1;i++){
                tmp=tmp->next;
            }
            node *temp=tmp->next;
            tmp->next=temp->next;
            tmp->next->prev=tmp;
            delete temp;
            this->size-=1;
        }
    }
}

void dll::displayForwards(){
    node* temp=this->head;
    std::cout<<"{ ";
    while(temp){
        std::cout<<temp->value<<" ";
        temp=temp->next;
    }
    std::cout<<"}\n";
}

void dll::displayBackwards(){
    node* temp=this->tail;
    std::cout<<"{ ";
    while(temp){
        std::cout<<temp->value<<" ";
        temp=temp->prev;
    }
    std::cout<<"}\n";
}

int dll::getFirst(){
    return head->value;
}

int dll::getLast(){
    return tail->value;
}

bool dll::isEmpty(){
    return head==nullptr&&tail==nullptr;
}

int dll::getLength(){
    return this->size;
}



std::ostream& operator<<(std::ostream &out,const dll& rhs){
    dll::node *temp=rhs.head;
    out<<"{ ";
    while(temp){
        out<<temp->value<<" ";
        temp=temp->next;
    }
    out<<"}"<<std::endl;
    return out;    
}

dll::~dll(){
    while(head){
        node* temp=head;
        head=head->next;
        delete temp;
    }
    std::cerr<<"DELETE\n";
}

dll::dll(const dll&rhs){
    this->head=this->tail=nullptr;
    node *temp=rhs.tail;
    while(temp){
        this->addFirst(temp->value);
        temp=temp->prev;
    }
    this->size=rhs.size;
    std::cerr<<"COPY\n";
    
}

const dll& dll::operator =(const dll&rhs){
    if(this==&rhs){
        return *this;
    }
    while(head){
        node* temp=head;
        head=head->next;
        delete temp;
    }
    
    this->head=this->tail=nullptr;
    node *temp=rhs.tail;
    while(temp){
        this->addFirst(temp->value);
        temp=temp->prev;
    }
    this->size=rhs.size;
    std::cerr<<"ASSIGNMENT\n";
    return *this;
}

#endif