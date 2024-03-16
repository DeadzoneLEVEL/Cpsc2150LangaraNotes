#include<iostream>
#include "priorityQueue.h"

int main(){
    pq smth(7);
    for(int i=1;i<=10;i++){
        smth.enqueue(i);
    }
    smth.showSkipList();
    smth.show();
    smth.process();
    smth.show();
    smth.enqueue(64);
    smth.enqueue(234);
    smth.enqueue(23);
    smth.showSkipList();
    smth.show();
    smth.dequeue();
    smth.dequeue();
    smth.show();
    smth.dequeue();
    smth.show();
    return 0;
}