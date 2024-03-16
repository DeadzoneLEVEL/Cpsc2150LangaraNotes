#ifndef DEC2SKIPLIST_H
#define DEC2SKIPLIST_H
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
        int coinflipping();
    public:
        skiplist(int);
        void insert(int);
        void deleteItem(int);
        bool search(int);
        void display();

        friend std::ostream& operator<<(std::ostream& out,const skiplist &rhs);
        int length();
        int* getValues();
        ~skiplist();
        skiplist(const skiplist &rhs);
        const skiplist& operator=(const skiplist &rhs);
};

skiplist::skiplist(int height){
    srand(time(0));
    this->currentlvl=0;
    this->maxlvl=height-1;
    this->size=0;
    this->head=new node(INT_MIN,height);
    for(int i=0;i<height;i++){
        head->next[i]=nullptr;
    }
}

int skiplist::coinflipping(){
    int ret=0;
    bool control=rand()%2;
    while(ret<maxlvl&&control){
        ret+=1;
        control=rand()%2;
    }
    return ret;
}

void skiplist::insert(int val){
    int vallvl=coinflipping();
    for(int i=vallvl;i>=0;i--){
        
    }
}


#endif