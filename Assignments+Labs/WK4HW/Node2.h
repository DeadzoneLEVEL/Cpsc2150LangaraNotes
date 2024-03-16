#ifndef NODE2_H
#define NODE2_H

#include <vector>

using namespace std;

// the node
class Node{
public:
    int value;
    unsigned int priority;
    // Array of pointers to the next nodes (which are located at various levels)
    vector<Node*> next; 
    vector<Node*> prev; 
    Node(int val, int level, int prior=0){
        value = val;
        priority=prior;
        next = vector<Node*>(level+1, nullptr); // initialize array of pointers to nulls
        prev = vector<Node*>(level+1, nullptr);
    };
};

#endif