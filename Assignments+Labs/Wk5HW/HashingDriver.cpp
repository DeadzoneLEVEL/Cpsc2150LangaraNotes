#include<iostream>
// #include "HashingLinear.h"
#include "HashingChain.h"

void hashinglinearDriver();
void hashingChainDriver();

int main(){
    // hashinglinearDriver();
    hashingChainDriver();
    return 0;
}
void hashingChainDriver(){
    HashingLinearProbingDemo arr(10,0.8,5);
    arr.Insert(4);
    arr.Insert(13);
    arr.Insert(23);
    arr.display();
    std::cout<<std::boolalpha<<arr.search(13)<<std::endl;
    std::cout<<std::boolalpha<<arr.search(10)<<std::endl;
    arr.Insert(5);
    arr.display();
    arr.Delete(5);
    arr.display();
    arr.Insert(1);
    arr.Insert(2);
    arr.Insert(3);
    arr.Insert(7);
    arr.Insert(6);
    arr.display();
    arr.Insert(9);
    arr.display();
    std::cout<<"done\n";
}

void hashinglinearDriver(){
    // HashingLinearProbingDemo arr(10,0.8);
    // arr.display();
    // arr.Insert(4);
    // arr.Insert(3);
    // arr.Insert(2);
    // arr.Insert(5);
    // arr.Insert(6);
    // arr.Insert(1);
    // arr.Insert(7);
    // arr.Insert(8);
    // arr.display();
    // arr.Insert(9);
    // arr.display();
    // arr.Insert(10);
    // arr.display();
    // arr.Delete(10);
    // arr.display();
    // std::cout<<std::boolalpha<<arr.search(9)<<std::endl;
    // std::cout<<std::boolalpha<<arr.search(10)<<std::endl;
    // arr.display();
    // arr.Delete(1);
    // arr.Delete(2);
    // arr.Delete(3);
    // arr.Delete(4);
    // arr.display();
    // std::cout<<"new hash:\n";
    // HashingLinearProbingDemo brr(arr);
    // brr.display();
    // brr.Insert(64);
    // brr.Delete(7);
    // arr=brr;
    // arr.display();
}