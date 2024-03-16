#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <iostream>
#include <ctime>
#include "SkipList.h"
#include "Node2.h"
#include <vector>
    class pq{
        private:
            SkipList arr;
            int size;
            struct info{
                int value;
                int priority;
            };
            std::vector<info> queueMembers;
        public:
            pq(int);
            int dequeue();
            void enqueue(int);
            void process();
            void show();
            void showSkipList();
            void simpleSort(std::vector<info>&);
    };

    pq::pq(int max){
        arr=SkipList (max);
        srand(time(0));
        this->size=0;
    }

    int pq::dequeue(){
        Node *todel=arr.tail->prev[arr.currentHighestLevelIndex];
        int ret=todel->value;
        arr.Delete(todel);
        size-=1;
        return ret;
    }
    void pq::enqueue(int value){
        int random=(rand()%(arr.MAXIMUM_ALLOWED_LEVEL_INDEX+1));
        arr.InsertElement(value,random);
        size+=1;
    }
    void pq::process(){
        Node *current=arr.tail;
        int lastKnownSize=this->size;
        int value;
        std::cout<<"List dequeued in order: ";
        for(int i=0;i<lastKnownSize-1;i++){
            value=this->dequeue();
            std::cout<<"[Value: "<<value<<"]->";
        }
        value=this->dequeue();
        std::cout<<"[Value: "<<value<<"]\n";
    }

    void pq::show(){
        if(this->size==0){
            std::cerr<<"ERROR: queue is empty.\n";
        }else{
            Node* current=arr.head;
            info node;
            while(current->next[0]!=arr.tail){
                current=current->next[0];
                node.priority=current->priority;
                node.value=current->value;
                queueMembers.push_back(node);
            }
            simpleSort(queueMembers);
            std::cout<<"Queue from highest priority to lowest priority:\n";
            for(int i=this->size-1;i>=0;i--){
                std::cout<<"Value: "<<queueMembers[i].value;
                std::cout<<" Priority: "<<queueMembers[i].priority<<std::endl;
            }
            queueMembers.clear();
        }
    }

    void pq::showSkipList(){
        arr.ShowForward();
    }
    void pq::simpleSort(std::vector<info> &v){
    int i,j;
    info tmp;
    for(i=1;i<v.size();i++){
        tmp=v[i];
        for(j=i-1;j>=0&&v[j].priority>tmp.priority;j--){
            v[j+1]=v[j];
        }
        v[j+1]=tmp;
    }
}

#endif