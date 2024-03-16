#include <iostream>
#include <fstream>
#include "CircularList.h"
#include "RoundRobin.h"

// g++ -pedantic -Wall -Wextra -std=c++17 driver.cpp -o driver


int main(){
    CircularLinkedList arr2;
    // arr2.insert(14,2);
    // arr2.display();
    // arr2.deleteNode(arr2.getPointer());
    // std::cout<<"No failsafe...\n";
    // arr2.display();
    // for(int i=0;i<20;i++){
    //     arr2.insert(i+1,i+1);
    // }
    // arr2.display();

    // for(int i=0;i<20;i++){
    //     arr2.insert(i+1,i+1);
    // }
    // arr2.display();
    // std::cout<<arr2.getPointer()->next->next->next->data<<std::endl;
    // arr2.deleteNode(arr2.getPointer()->next->next->next);
    // arr2.display();
    // std::cout<<arr2.getPointer()->data<<std::endl;
    // std::cout<<arr2.getPointer()->next->data<<std::endl;
    // arr2.deleteall();
    // std::cout<<"It got here2\n";
    // arr2.insert(12,1);
    // arr2.insert(17,1);
    // arr2.display();
    // std::cout<<arr2.getPointer()->data<<std::endl;
    // std::cout<<arr2.getPrevPointer()->data<<std::endl;
    // arr2.deleteNode(arr2.getPointer()->next->next);
    // std::cout<<std::boolalpha<<arr2.isEmpty()<<std::endl;
    // arr2.insert(13,1);
    // arr2.display();
    // std::cout<<std::boolalpha<<arr2.isEmpty()<<std::endl;
    // arr2.insert(25,1);
    // std::cout<<arr2.getPointer()->data<<std::endl;
    // arr2.deleteNode(arr2.getPointer());
    // std::cout<<arr2.getPointer()->data<<std::endl;
    // arr2.display();

    RoundRobinProcessScheduler arr;
    arr.LoadFromFile("process.txt");
    // arr.display();
    arr.process();
    // std::cout<<"No failsafe...\n";
    arr.showResults();
    arr.LoadFromFile("process2.txt");
    arr.process();
    arr.showResults();
    // std::cout<<"It got here\n";
    // arr.display();
    return 0;
}
