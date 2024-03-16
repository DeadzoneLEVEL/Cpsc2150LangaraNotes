#ifndef MYSKIPLIST_H
#define MYSKIPLIST_H
#include <iostream>
#include <ctime>
#include <climits>
#include <vector>

class node{
    public:
        int value;
        std::vector<node*> next;
        node(int val,int level);
};

node::node(int val,int level){
    this->value=val;
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
    public:
        skiplist(int);
        int coinflipping();
        void insert(int);
        void deleteItem(int);
        bool search(int);
        void display();

        friend std::ostream& operator<<(std::ostream& out,const skiplist &rhs);
        int length();
        int* getValues();
        ~skiplist();
        // skiplist(const skiplist &rhs);
        // const skiplist& operator=(const skiplist &rhs);
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
        while(current->next[i]!=nullptr){
            current=current->next[i];
            std::cout<<current->value;
            std::cout<<"->";
        }
        std::cout<<"nullptr.\n";
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

#endif