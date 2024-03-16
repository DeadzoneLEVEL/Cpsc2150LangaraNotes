#include <iostream>
#include <vector>
#include "MySkipList.h"
#include <ctime>

int main(){
    srand(time(0));
    skiplist arr(7);
    skiplist brr(4);
    for(int i=0;i<10;i++){
        arr.insert((rand()%100)+1);
        brr.insert((rand()%100)+1);
    }
    arr.display();
    std::cout<<"------------------------------------------------------------------\n";
    brr.display();
    // int t=arr.findLastElement();
    // int t=arr.findMiddleElement();
    // std::cout<<t<<std::endl;
    skiplist grr(brr);
    // std::cout<<"------------------------------------------------------------------\n";
    // grr.display();
    // grr=arr;
    // std::cout<<"------------------------------------------------------------------\n";
    // grr.display();
    grr=arr+brr;
    std::cout<<"------------------------------------------------------------------\n";
    grr.display();
    std::cout<<"------------------------------------------------------------------\n";
    brr.display();
    grr=grr.intersection(brr);
    std::cout<<"------------------------------------------------------------------\n";
    grr.display();
    grr.eraseItems(80,13);
    std::cout<<"------------------------------------------------------------------\n";
    grr.display();
    return 0;
}