#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

class ll{
    public:
    ll();
    friend std::ostream& operator<<(std::ostream &out,const ll &rhs);
    friend ll operator+(const ll &lhs,const ll &rhs);
    void del();
    void add(std::string x);
    void reverse();
    ~ll();
    ll(const ll &rhs);
    const ll& operator =(const ll &rhs);
    private:
        struct node{
            std::string data;
            node *next;
        };
        node *head;
        node* revere(node *rhs);
        ll(node *p);
};

ll::ll(){
    head=nullptr;
}


std::ostream& operator<<(std::ostream &out,const ll &rhs){
    ll::node *temp=rhs.head;
    out<<"{ ";
    while(temp){
        out<<temp->data<<" ";
        temp=temp->next;
    }
    out<<"}"<<std::endl;
    return out;
}

ll::ll(node *p){
    head=p;
}

ll operator+(const ll &lhs,const ll &rhs){
    ll::node * result=nullptr;
    ll t(lhs.head);
    t.reverse();
    ll t2(rhs.head);
    t2.reverse();
    ll::node *tmp1=t.head,*tmp2=t2.head;
    while(tmp1){
        result=new ll::node{tmp1->data,result};
        tmp1=tmp1->next;
    }
    while(tmp2){
        result=new ll::node{tmp2->data,result};
        tmp2=tmp2->next;
    }
    
    return result;
}

void ll::del(){
    while(head){
        node *tmp=head;
        head=head->next;
        delete tmp;
    }
}

void ll::add(std::string x){
    head=new node{x,head};
}


void ll::reverse()
{
    head=revere(head);
}
ll::node* ll::revere(node *rhs){
    node* tmp=rhs;
    node *result=nullptr;
    // std::cout<<"Here2\n";
    while(tmp){
        // std::cout<<"Here3\n";
        // node* tmp2=tmp;
        result=new node{tmp->data,result};
        tmp=tmp->next;
        // delete tmp2;
    }
    return result;
}

ll::~ll(){
    while(head){
        node *tmp=head;
        head=head->next;
        delete tmp;
    }
    std::cerr<< "DELETE"<<std::endl;
}

ll::ll(const ll &rhs){
    head=nullptr;
    node *tmp=revere(rhs.head);
    while(tmp){
        this->head=new node{tmp->data,head};
        node *tmp2=tmp;
        tmp=tmp->next;
        delete tmp2;
    }
    std::cerr<< "COPY"<<std::endl;
}

const ll& ll::operator =(const ll &rhs){
    if(this==&rhs){
        return *this;
    }
    while(head){
        node *tmp=head;
        head=head->next;
        delete tmp;
    }
    head=nullptr;
    node *tmp=revere(rhs.head);
    while(tmp){
        node *tmp2=tmp;
        this->head=new node{tmp->data,head};
        tmp=tmp->next;
        delete tmp2;
    }
    std::cerr<< "ASSIGNMENT"<<std::endl;
    return *this;
}

#endif
