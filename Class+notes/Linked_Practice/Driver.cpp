#include <iostream>
#include <cmath>
#include <ctime>
#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"
#include "stack.h"
#include "MySkipList.h"

void LinkedListDriver();
void DoublyLinkedListDriver();
void CircularLinkedListDriver();
void stackDriver();
void skiplistDriver();
void roundRobin();

int main(){
    // LinkedListDriver();
    // DoublyLinkedListDriver();
    // CircularLinkedListDriver();
    // stackDriver();
    skiplistDriver();
    // roundRobin();
    return 0;
}

void skiplistDriver(){
    skiplist smth(5);
    for(int i=1;i<=10;i++){
        // std::cerr<<"It got here\n";
        smth.insert(i*2);
    }
    // smth.insert(5);
    // smth.insert(7);
    smth.display();
    std::cout<<std::boolalpha<<smth.search(5)<<std::endl;
    std::cout<<std::boolalpha<<smth.search(9)<<std::endl;
    std::cout<<std::boolalpha<<smth.search(-5)<<std::endl;
    smth.deleteItem(20);
    smth.display();
    smth.deleteItem(2);
    smth.display();
    for(int i=1;i<=10;i++){
        smth.deleteItem(i*2);
    }
    smth.display();
    std::cout<<smth.length()<<std::endl;
    smth.insert(25);
    smth.display();
    std::cout<<smth.length()<<std::endl;
    std::cout<<smth;
}

void stackDriver(){
    ss smth;
    for(int i=0;i<10;i++){
        smth.push(i*2+3);
    }
    smth.display();
    ss smthnew(smth);
    smthnew.push(24);
    smthnew.display();
    std::cout<<smthnew.length()<<std::endl;
    smth.display();
    std::cout<<smth.length()<<std::endl;
    smth=smthnew;
    smth.display();
}

void roundRobin(){

}
void CircularLinkedListDriver(){
    cll smth;
    for(int i=0;i<5;i++){
        smth.add(i+1);
    }
    smth.display();
    smth.remove(4);
    smth.display();
    smth.remove(-2);
    smth.display();
    smth.remove(1);
    smth.display();
    smth.remove(1);
    smth.display();
    smth.remove(0);
    smth.display();
    std::cout<<smth;
    std::cout<<smth.getLength()<<std::endl;
    for(int i=0;i<5;i++){
        smth.add(i+1);
    }
    cll smth2(smth);
    for(int i=0;i<5;i++){
        smth.add(i+1);
    }
    std::cout<<smth;
    std::cout<<smth2;
    smth=smth2;
    std::cout<<smth;
}

void DoublyLinkedListDriver(){
    dll stuff;
    for(int i=0;i<10;i++){
        stuff.addFirst(i*3+2);
    }
    stuff.displayForwards();
    stuff.displayBackwards();
    stuff.addFirst(69);
    stuff.displayForwards();
    stuff.addLast(73);
    stuff.displayBackwards();
    std::cout<<stuff.getLength()<<std::endl;
    std::cout<<stuff.getFirst()<<std::endl;
    std::cout<<stuff.getLast()<<std::endl;
    stuff.displayForwards();
    stuff.remove(9);
    stuff.displayForwards();
    stuff.remove(-1);
    stuff.displayForwards();
    stuff.remove(0);
    stuff.displayForwards();
    stuff.remove(9);
    stuff.displayForwards();
    stuff.remove(37);
    stuff.displayForwards();
    stuff.remove(6);
    stuff.displayForwards();
    dll stuff2(stuff);
    stuff.remove(1);
    stuff.displayForwards();
    std::cout<<stuff.getLength()<<std::endl;
    stuff2.displayForwards();
    std::cout<<stuff2.getLength()<<std::endl;
    dll stuff3=stuff2;
    stuff3.displayForwards();
    std::cout<<stuff3.getLength()<<std::endl;
}

void LinkedListDriver(){
    ll stuff;
    for(int i=0;i<7;i++){
        stuff.add(i+1);
    }
    std::cout<<stuff<<std::endl;
    int x=stuff.getLast();
    int xx=stuff.getFirst();
    int xy=stuff.getLength();
    std::cout<<"Last: "<<x<<" First: "<<xx<<" Length: "<<xy<<std::endl;
    std::cout<<stuff<<std::endl;
    std::cout<<std::boolalpha<<stuff.isEmpty()<<std::endl;
    ll stuff2(stuff);
    stuff2.add(23);
    stuff2.add(45);
    std::cout<<stuff2;
    ll stuff3(stuff);
    std::cout<<stuff3;
    stuff3=stuff2;
    std::cout<<stuff3;
    stuff3.remove(-1);
    stuff3.remove(56);
    std::cout<<stuff3;
    std::cout<<stuff3.getLength()<<std::endl;
    stuff3.remove(4);
    std::cout<<stuff3;
    std::cout<<stuff3.getLength()<<std::endl;
    stuff3.remove(6);
    std::cout<<stuff3;
    std::cout<<stuff3.getLength()<<std::endl;
    stuff3.remove(0);
    std::cout<<stuff3;
    std::cout<<stuff3.getLength()<<std::endl;
}