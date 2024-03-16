#ifndef MYSKIPLIST_H
#define MYSKIPLIST_H
#include <iostream>
#include <ctime>
#include <climits>
#include <vector>

class node{
    public:
        int value;
        int lvl;
        std::vector<node*> next;
        node(int val,int level);
};

node::node(int val,int level){
    this->value=val;
    this->lvl=level;
    next=std::vector<node*>(level+1,nullptr);
}

/**
 * @brief ordered skiplist with no repeating values
 * 
 */
class skiplist{
    private:
        node* head;   
        int currentlvl;
        int maxlvl;
        int size;
        int coinflipping();
        void insert(int x,int abslvl);
    public:
        skiplist(int);
        void insert(int);
        void deleteItem(int);
        bool search(int);
        void display();
        int findLastElement();
        int findMiddleElement();
        skiplist intersection(const skiplist&rhs);
        void eraseItems(int,int);

        friend skiplist operator+(const skiplist &lhs,const skiplist &rhs);
        // skiplist operator+(const skiplist &other) const ;
        friend std::ostream& operator<<(std::ostream& out,const skiplist &rhs);
        int length();
        int* getValues();
        ~skiplist();
        skiplist(const skiplist &rhs);
        const skiplist& operator=(const skiplist &rhs);
};

skiplist::skiplist(int maxindex){
    srand(time(0));
    maxlvl=maxindex-1;
    currentlvl=0;
    size=0;
    head=new node(INT_MIN,maxlvl);
}

int skiplist::coinflipping(){
    int ret=0;
    bool control=rand()%2;
    while(ret<maxlvl&&control==true){
        ret+=1;
        control=rand()%2;
    }
    return ret;
}

void skiplist::insert(int x){
    node *current = head;
    std::vector<node*> update(maxlvl+1, nullptr);
    for(int i=currentlvl;i>=0;i--){
        while(current->next[i]!=nullptr&&current->next[i]->value<x){
            current=current->next[i];
        }
        update[i]=current;
    }
    current=current->next[0];
    if(current==nullptr||current->value!=x){
        int randomlvl=coinflipping();
        if(randomlvl>currentlvl){
            for (int i=currentlvl+1;i<=randomlvl;i++){
                 update[i] = head;
            }
            currentlvl=randomlvl;
        }
        node *tmp=new node(x,randomlvl);
        for(int i=randomlvl;i>=0;i--){
            tmp->next[i]=update[i]->next[i];
            update[i]->next[i]=tmp;
        }
    }
    // std::cerr<<"It got here\n";
    size+=1;
}
void skiplist::insert(int x,int abslvl){
    if(abslvl>maxlvl){
        abslvl=maxlvl;
    }
    node *current = head;
    std::vector<node*> update(maxlvl+1, nullptr);
    for(int i=currentlvl;i>=0;i--){
        while(current->next[i]!=nullptr&&current->next[i]->value<x){
            current=current->next[i];
        }
        update[i]=current;
    }
    current=current->next[0];
    if(current==nullptr||current->value!=x){
        if(abslvl>currentlvl){
            for (int i=currentlvl+1;i<=abslvl;i++){
                 update[i] = head;
            }
            currentlvl=abslvl;
        }
        node *tmp=new node(x,abslvl);
        for(int i=abslvl;i>=0;i--){
            tmp->next[i]=update[i]->next[i];
            update[i]->next[i]=tmp;
        }
    }
    // std::cerr<<"It got here\n";
    size+=1;
}

void skiplist::deleteItem(int x){
    node*current=head;
    std::vector<node*> update(maxlvl+1, nullptr);
    for(int i=currentlvl;i>=0;i--){
        while(current->next[i]!=nullptr&&current->next[i]->value<x){
            current=current->next[i];
        }
        if(current->next[i]!=nullptr&&current->next[i]->value==x){
            update[i]=current;
        }
        // std::cout<<"It got here\n";
    }
    current=current->next[0];
    if(current!=nullptr&&current->value==x){
        for(int i=currentlvl;i>=0;i--){
            if(update[i]){
                update[i]->next[i]=current->next[i];
                // current->next[i]=nullptr;
            }
        }
        size-=1;
        delete current;
        while (currentlvl >= 0 && head->next[currentlvl] == nullptr){
            currentlvl-=1;
        }
    }else{
        std::cerr<<"ERROR: no node with "<<x<<" found.\n";
    }
}

bool skiplist::search(int x){
    node* current=head;
    for(int i=currentlvl;i>=0;i--){
        while(current->next[i]!=nullptr&&current->next[i]->value<x){
            current=current->next[i];
        }
        if(current->next[i] != nullptr &&current->next[i]->value==x){
            return true;
        }
    }    
    return false;
}

void skiplist::display(){
    if(head->next[0]==nullptr){
        std::cout<<"Skiplist empty.\n";
        return;
    }
    node* current;
    for(int i=currentlvl;i>=0;i--){
        current=head;
        std::cout<<"Head->";
        while(current->next[i]!=nullptr&&current!=nullptr){
            current=current->next[i];
            std::cout<<current->value;
            std::cout<<"->";
        }
        std::cout<<"nullptr.\n";
    }
}

int skiplist::findLastElement(){
    node* current=this->head;
    while(current->next[0]!=nullptr){
        current=current->next[0];
    }
    return current->value;
}

int skiplist::findMiddleElement(){
    node* fast=this->head;
    node* slow=this->head;
    while(fast->next[0]!=nullptr){
        fast=fast->next[0]->next[0];
        slow=slow->next[0];
    }
    return slow->value;
}

skiplist operator+(const skiplist &lhs,const skiplist &rhs){
    int max;
    if(rhs.maxlvl>lhs.maxlvl){
        max=rhs.maxlvl;
    }else{
        max=lhs.maxlvl;
    }
    skiplist ret(max);
    node* current=lhs.head;
    while(current->next[0]!=nullptr&&current!=nullptr){
        current=current->next[0];
        ret.insert(current->value,current->lvl);
    }
    current=rhs.head;
    while(current->next[0]!=nullptr&&current!=nullptr){
        current=current->next[0];
        ret.insert(current->value,current->lvl);
    }
    return ret;
}

skiplist skiplist::intersection(const skiplist&rhs){
    node* other=rhs.head->next[0];
    node* thisone=this->head->next[0];
    int max;
    if(rhs.maxlvl>this->maxlvl){
        max=rhs.maxlvl;
    }else{
        max=this->maxlvl;
    }
    skiplist ret(max);
    while(other!=nullptr&&thisone!=nullptr){
        if(other->value==thisone->value){
            ret.insert(thisone->value);
            other=other->next[0];
            thisone=thisone->next[0];
        }else if(other->value>thisone->value){
            thisone=thisone->next[0];
        }else{
            other=other->next[0];
        }
    }
    return ret;
}

void skiplist::eraseItems(int low,int high){
    if(low>high){
        int tmp=low;
        low=high;
        high=tmp;
    }
    if(low==high){
        this->deleteItem(low);
    }
    std::vector<int> todel;
    node* current=this->head;
    while(current->next[0]!=nullptr&&current!=nullptr){
        current=current->next[0];
        if(current->value>=low&&current->value<=high){
            todel.push_back(current->value);
        }
    }
    for(unsigned i=0;i<todel.size();i++){
        this->deleteItem(todel[i]);
    }
}


std::ostream& operator<<(std::ostream& out,const skiplist &rhs){
    if(rhs.head->next[0]==nullptr){
        out<<"Skiplist empty.\n";
    }else{
        node* current;
        for(int i=rhs.currentlvl;i>=0;i--){
            current=rhs.head;
            out<<"Head->";
            while(current->next[i]!=nullptr){
                current=current->next[i];
                out<<current->value;
                out<<"->";
            }
            out<<"nullptr.\n";
        }
    }
    return out;
}

int skiplist::length(){
    return size;
}
int* skiplist::getValues(){
    int *arr=new int[size];
    node *tmp=head->next[0];
    for(int i=0;i<size;i++){
        arr[i]=tmp->value;
        tmp=tmp->next[0];
    }
    return arr;
}

skiplist::~skiplist(){
    node *current=head->next[0];
    while(current->next[0]!=nullptr){
        node *todel=current;
        current=current->next[0];
        delete todel;
    }
    size=0;
}

skiplist::skiplist(const skiplist &rhs){
    srand(time(0));
    this->maxlvl=rhs.maxlvl;
    this->currentlvl=rhs.currentlvl;
    this->size=0;
    head=new node(INT_MIN,maxlvl);
    node*current=rhs.head;
    while(current->next[0]!=nullptr){
        current=current->next[0];
        this->insert(current->value,current->lvl);
    }
}

const skiplist& skiplist::operator=(const skiplist &rhs){
    srand(time(0));
    if(this==&rhs){
        return *this;
    }
    node *current=head->next[0];
    while(current->next[0]!=nullptr){
        node *todel=current;
        current=current->next[0];
        delete todel;
    }
    size=0;
    this->maxlvl=rhs.maxlvl;
    this->currentlvl=rhs.currentlvl;
    this->size=0;
    head=new node(INT_MIN,maxlvl);
    current=rhs.head;
    while(current->next[0]!=nullptr){
        current=current->next[0];
        this->insert(current->value,current->lvl);
    }
}
#endif