#include<iostream>
#include<vector>
#include "liangBST.h"

int main(){
    int ele[]={12,45,34,96,12,2,4,3};
    BST arr(ele,8);
    arr.DisplayTreeHorizontally();
    arr.SaveTreeToFileBFS("data.txt");
    arr.clear();
    arr.LoadTreeFromFile("data.txt");
    std::cout<<"-------------------------------------------------------\n";
    arr.DisplayTreeHorizontally();
    std::cout<<"-------------------------------------------------------\n";
    // arr.kthSmallest(4);
    // std::cout<<std::endl;
    // TreeNode* cca=arr.ClosestCommonAncestor(arr.search(34),arr.search(96));
    // std::cout<<cca->element<<std::endl;
    // cca=arr.ClosestCommonAncestor(arr.search(3),arr.search(34));
    // std::cout<<cca->element<<std::endl;
    BST brr;
    brr.insert(4);
    brr.insert(2);
    brr.insert(12);
    brr.insert(96);
    brr.insert(34);
    brr.insert(45);
    std::cout<<"-------------------------------------------------------\n";
    brr.DisplayTreeHorizontally();
    std::cout<<"-------------------------------------------------------\n";
    std::cout<<std::boolalpha<<(arr==brr)<<std::endl;
    brr=arr;
    std::cout<<"-------------------------------------------------------\n";
    brr.DisplayTreeHorizontally();
    std::cout<<"-------------------------------------------------------\n";
    std::cout<<std::boolalpha<<(arr==brr)<<std::endl;
    brr.insert(100);
    std::cout<<std::boolalpha<<(arr==brr)<<std::endl;
    int ele2[]={4,2,12,96,34,45};
    BST test1(ele2,6,false);
    std::cout<<"-------------------------------------------------------\n";
    test1.DisplayTreeHorizontally();
    std::cout<<"-------------------------------------------------------\n";
    BST test2(ele2,6,true);
    std::cout<<"-------------------------------------------------------\n";
    test2.DisplayTreeHorizontally();
    std::cout<<"-------------------------------------------------------\n";
    std::cout<<test2.NodesWithOddValues()<<std::endl;
    test2.LevelOrderDisplay();
    test2.IncrementByOne();
    std::cout<<"-------------------------------------------------------\n";
    test2.DisplayTreeHorizontally();
    std::cout<<"-------------------------------------------------------\n";
    std::cout<<test2.NodesWithOddValues()<<std::endl;
    return 0;
}
