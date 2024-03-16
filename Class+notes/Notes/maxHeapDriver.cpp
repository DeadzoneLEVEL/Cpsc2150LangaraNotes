#include <iostream>
#include "maxHeap.h"

using namespace std;

int main(){
    MAXHEAP m;

    m.insert(30);

    // m.DisplayTreeHorizontally();

    m.insert(25);

    // m.DisplayTreeHorizontally();

    m.insert(15);
    m.insert(10);
    m.insert(5);
    
    m.insert(45);
    m.insert(65);

    m.insert(150);
    m.insert(100);
    m.insert(50);
    
    m.insert(450);
    m.insert(650);
m.DisplayTreeHorizontally();
    return 0;
}