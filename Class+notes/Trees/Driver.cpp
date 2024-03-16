#include<iostream>
#include<vector>
#include "bst.h"
// #include "graph2.h"
#include "graph.h"

void BinarySearchTree(){
     int ele[]={12,75,4,5,100,65};
    bst test(ele,6);
    std::cout<<"Current Tree:\n";
    std::cout<<"-------------------------------------------------------\n";
    test.DisplayTreeHorizontally();
    std::cout<<"-------------------------------------------------------\n";
    std::cout<<"Test Search:\n";
    std::cout<<"4:"<<std::boolalpha<<test.search(4)<<std::endl;
    std::cout<<"74:"<<std::boolalpha<<test.search(74)<<std::endl;
    std::cout<<"Test height:\n";
    std::cout<<test.height()<<std::endl;
    std::cout<<"Test Order:\n";
    test.inOrderTraversal();
    test.preOrderTraversal();
    test.postOrderTraversal();
    std::cout<<"Test parent:\n";
    test.printParent();
    std::cout<<"Test Num of Leaves:\n";
    std::cout<<test.getNumberOfleaves()<<std::endl;
    std::cout<<test.getNumberOfNonleaves()<<std::endl;
    std::cout<<"Test Is Perfect:\n";
    std::cout<<std::boolalpha<<test.isPerfect()<<std::endl;
    test.insert(1);
    std::cout<<std::boolalpha<<test.isPerfect()<<std::endl;
    std::cout<<"-------------------------------------------------------\n";
    test.DisplayTreeHorizontally();
    std::cout<<"-------------------------------------------------------\n";
    test.mirror();
    std::cout<<"-------------------------------------------------------\n";
    test.DisplayTreeHorizontally();
    std::cout<<"-------------------------------------------------------\n";
    int ele2[]={3,71,7,0,420,69,13};
    bst test2(ele2,7);
    std::cout<<"-------------------------------------------------------\n";
    test2.DisplayTreeHorizontally();
    std::cout<<"-------------------------------------------------------\n";
    bst test3;
    test3=test+test2;
    std::cout<<"-------------------------------------------------------\n";
    test3.DisplayTreeHorizontally();
    std::cout<<"-------------------------------------------------------\n";
    std::cout<<"{";
    for(unsigned i=0;i<test3.length();i++){
        std::cout<<test3[i]<<" ";
    }
    std::cout<<"}\n";
    return;
}
void Graphs(){
    unsigned mat[4][4]={
    {0,1,0,0},
    {1,0,0,1},
    {0,0,0,1},
    {0,1,1,0}};
    graph g(mat,4,4);
    // std::cout<<std::boolalpha<<g.isConnected()<<std::endl;
    // std::cout<<std::boolalpha<<g.IsDirected()<<std::endl;
    std::cout<<g.countIslands()<<std::endl;
}

int main(){
    // BinarySearchTree();
    Graphs();
    return 0;
}