#include <iostream>
#include "Stacking.h"
#include "queue.h"
#include "LinkedListFull.h"
/**
 * @author Gregory bennett 
 */

int main(){
    ss t;
    t.push(1);
    t.push(2);
    t.push(3);
    t.push(4);
    int num=t.peek();
    std::cout<<num<<std::endl; 
    t.print();
    num=t.pop();
    std::cout<<num<<std::endl; 
    t.push(5);
    t.print();
    std::cout<<t.peek()<<std::endl;
    ss k(t);
    ss m=k;
    k.print();
    m.print();
    
    LinkedList<int> ll;
    for(int i=0;i<5;i++){
        ll.add(i+1);
    }
    ll.Show();
    ll.removeLast();
    ll.Show();
    ll.add(3,54);
    ll.Show();
    bool sum=ll.contains(54);
    std::cout<<std::boolalpha<<sum<<std::endl;

    qq smth;
    smth.enqueue(2);
    smth.enqueue(3);
    smth.enqueue(9);
    int xx=smth.peekfront();
    int xy=smth.peekrear();
    std::cout<<xx<<","<<xy<<std::endl;
    smth.dequeue();
    xy=smth.peekfront();
    std::cout<<xy<<std::endl;
    return 0;
}