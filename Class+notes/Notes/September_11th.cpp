#include <iostream>
#include <vector>
#include <cmath>
#include "linkedListFull.h"

int recursion(std::vector<int> &v,int i);

int main(){
    std::vector<int> v = {10,5,2,19};
    int t=recursion(v,0);
    std::cout<<t<<std::endl;
    LinkedList<int> ll;
    ll.addLast(65);
    ll.addLast(68);
    return 0;
}

int recursion(std::vector<int> &v,int i){
    if(i==v.size()){
        return 0;
    }
    return v[i]+recursion(v,i+1);
}