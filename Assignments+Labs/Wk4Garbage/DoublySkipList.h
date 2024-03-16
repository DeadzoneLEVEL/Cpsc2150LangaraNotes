#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include "Node2.h"


#ifndef DOUBLYSKIPLIST_H
#define DOUBLYSKIPLIST_H

using namespace std;

class DoublySkipList{
public:
    // Maximum number of levels allowed for this skip list
    int MAXIMUM_LEVEL_INDEX;
 
    // current maximum level amongst the inserted nodes
    int level;
    
    // the head node's next links are connected to the first node at every level
    Node *head;
    Node *tail;

    DoublySkipList(int maxLevels){
        MAXIMUM_LEVEL_INDEX = maxLevels;

        // initially we have the bottom-most level only
        level = 0;
    
        // create the header node, value is irrelevant (as long as it doesn't match an inserted value - NO REPEATS), number of next links is important (this node is connected to the first node at every level)
        head = new Node(INT_MIN, MAXIMUM_LEVEL_INDEX,0);
        tail= new Node(INT_MAX, MAXIMUM_LEVEL_INDEX,0);

        for(int i=0;i<maxLevels+1;i++){
            head->next[i]=tail;
            tail->prev[i]=head;
        }
    }
    DoublySkipList(){
        MAXIMUM_LEVEL_INDEX = 10;
        // initially we have the bottom-most level only
        level = 0;
    
        // create the header node, value is irrelevant (as long as it doesn't match an inserted value - NO REPEATS), number of next links is important (this node is connected to the first node at every level)
        head = new Node(INT_MIN, MAXIMUM_LEVEL_INDEX,0);
        tail= new Node(INT_MAX, MAXIMUM_LEVEL_INDEX,0);

        for(int i=0;i<11;i++){
            head->next[i]=tail;
            tail->prev[i]=head;
        }
    }
    int getMaxLevel(){
        return MAXIMUM_LEVEL_INDEX;
    }

    int RandomLevel(){
        float probablity = (float)rand()/RAND_MAX; // flip a coin
        int lvl = 0;
        while (probablity < 0.5 && lvl < MAXIMUM_LEVEL_INDEX){
            lvl++; // landed heads so increase level by 1
            probablity = (float)rand()/RAND_MAX; // flip a coin again
        }
        return lvl;        
    }

    Node* CreateNode(int value, int level,int priority){
        // create a new node with next links for every level that this node will be part of
        // it will use these links to connect to the next node at each level  
        return new Node(value, level,priority);
    }

    Node* getLast(){
        return tail;
    }

    // void InsertElement(int value){

    //     /**
    //      * THIS CODE HAS A BUG, 
    //      * 
    //      * ***********FIND THE BUG, 
    //      * *************EXPLAIN THE WHY THE BUG EXIST 
    //      * AND 
    //      * **********************SUGGEST A FIX         * 
    //      * 
    //      */

    //     Node *current = head; // start at head node
    //     vector<Node*> update(MAXIMUM_LEVEL_INDEX+1, nullptr); // this will hold the nodes that need updating at every level after the insert takes place
    //     /*O(log(n)???)*/for (int i = level; i >= 0; i--){
    //         // for level i, if value is to be inserted here then find out where (i.e. after which node)
    //         /*O(1)????*/while (current->next[i] != nullptr && current->next[i]->value < value){
    //             current = current->next[i];
    //         }
    //         // found the node after which the value is to be placed at level i

    //         update[i] = current;//how would this work if big three overload would provide a deep copy 
    //     }    
        
    //     current = current->next[0];
    
    //     if (current == nullptr || current->value != value){
    //         int ranLevel = RandomLevel(); // choose a random level upto where the new node will be placed
    
    //         if (ranLevel > level){
    //             // if random level for current node is higher than the current maximum level for the existing nodes then set updates for each level over current maximum to head (since there are no nodes at these levels yet).
    //             /*O(log(n))*/for (int i=level+1;i<=ranLevel;i++){
    //                 update[i] = head;
    //             }
    
    //             // also change the current maximum level for the existing nodes
    //             level = ranLevel;
    //         }

    //         for (int i=level+1;i<=ranLevel;i++){
    //             update[i] = head;
    //         }
    
    //         // create new node with next links for every level from ranLevel to zero
    //         Node* n = CreateNode(value, ranLevel);
    
    //         // placing new node in the correct place at every level
    //         for (int i=0;i<=ranLevel;i++){
    //             n->next[i] = update[i]->next[i];

    //             //this
    //             n->prev[i]=update[i];
    //             if(update[i]->next[i]!=nullptr){
    //                 update[i]->next[i]->prev[i]=n;
    //             }
    //             // std::cerr<<"it got here\n";
    //             update[i]->next[i] = n;

    //             // if(n->next[i]==nullptr){
    //             //     n->next[i]=tail;
    //             // }
    //         }
            
    //     }
           
    // }
    
    void InsertElement(int value,int priority){

        /**
         * THIS CODE HAS A BUG, 
         * 
         * ***********FIND THE BUG, 
         * *************EXPLAIN THE WHY THE BUG EXIST 
         * AND 
         * **********************SUGGEST A FIX         * 
         * 
         */
        if(priority>MAXIMUM_LEVEL_INDEX){
            priority=MAXIMUM_LEVEL_INDEX;
        }else if(priority<0){
            priority=0;
        }
        Node *current = head; // start at head node
        vector<Node*> update(MAXIMUM_LEVEL_INDEX+1, nullptr); // this will hold the nodes that need updating at every level after the insert takes place
        /*O(log(n)???)*/for (int i = level; i >= 0; i--){
            // for level i, if value is to be inserted here then find out where (i.e. after which node)
            // /*O(1)????*/while (current->next[i] != nullptr && current->next[i]->value < value){
                // current = current->next[i];
            // }
            // found the node after which the value is to be placed at level i

            update[i] = current;//how would this work if big three overload would provide a deep copy 
        }    
        
        current = current->next[0];
    
        if (current == nullptr || current->value != value){
            // int ranLevel = RandomLevel(); // choose a random level upto where the new node will be placed
    
            // if (ranLevel > level){
            //     // if random level for current node is higher than the current maximum level for the existing nodes then set updates for each level over current maximum to head (since there are no nodes at these levels yet).
            //     /*O(log(n))*/for (int i=level+1;i<=ranLevel;i++){
            //         update[i] = head;
            //     }
    
            //     // also change the current maximum level for the existing nodes
            //     level = ranLevel;
            // }
            if(priority>level){
                for (int i=level+1;i<=priority;i++){
                    update[i] = head;
                }
                level=priority;
            }
            // create new node with next links for every level from ranLevel to zero
            Node* n = CreateNode(value, priority, priority);
    
            // placing new node in the correct place at every level
            for (int i=0;i<=priority;i++){
                n->next[i] = update[i]->next[i];

                //this
                n->prev[i]=update[i];
                if(update[i]->next[i]!=nullptr){
                    update[i]->next[i]->prev[i]=n;
                }
                // std::cerr<<"it got here\n";
                update[i]->next[i] = n;

                // if(n->next[i]==nullptr){
                //     n->next[i]=tail;
                // }
            }
            
        }
           
    }

    void Delete(int value){
        // TO BE COMPLETED
        // remove value from skip list (all levels) if it exists (output a message if it does not exist)
        if(this->Search(value)){
            Node *temp=head;
            Node *todel;
            for (int i=level;i>=0;i--){
                while(temp->next[i]!=nullptr&&temp->next[i]->value<value){
                    temp= temp->next[i];
                }
                if(temp->next[i]!=nullptr&&temp->next[i]->value==value){
                    todel=temp->next[i];
                    temp->next[i]=temp->next[i]->next[i];

                    //this  
                    if(temp->next[i]!=nullptr){
                        temp->next[i]->prev[i]=temp;
                    }  
                }
            }
            delete todel;
        }else{
            std::cerr<<"ERROR: Node not found\n";
        }
    }

    void Delete(Node *current){
        // TO BE COMPLETED
        // remove value from skip list (all levels) if it exists (output a message if it does not exist)
        Node *temp=current;
        Node *todel;
            for (int i=current->priority;i>=0;i--){
                todel=temp;
                //this  
                if(temp->next[i]!=nullptr){
                    temp->prev[i]->next[i]=temp->next[i];
                    temp->next[i]->prev[i]=temp->next[i]->prev[i];
                }
            }
            delete todel;
    }

    bool Search(int value){
        // TO BE COMPLETED
        Node *temp=head;
        for (int i=level;i>=0;i--){
            while(temp->next[i]!=nullptr&&temp->next[i]->value<value){
                temp= temp->next[i];
            }
            if(temp->next[i]!=nullptr&&temp->next[i]->value==value){
                return true;
            }
        }
        return false;
        // search for value in skip list and return true if it exists; false otherwise
    }

    void Show(){
        for (int i=0;i<=level;i++){
            Node *node = head->next[i];
            cout << "Level " << i << ": ";
            while (node != nullptr && node->next[i] != tail){
                cout << node->value << " -> ";
                node = node->next[i];
            }
            if(node!=nullptr||node!=tail){
                cout << node->value << " .\n";
            }
        }
    }

    void ShowBackward(){
        for (int i=0;i<=level;i++){
            Node *node = tail->prev[i];
            cout << "Level " << i << ": ";
            while (node != nullptr && node->prev[i] != head){
                cout << node->value << " -> ";
                node = node->prev[i];
            }
            if(node!=nullptr||node!=head){
                cout << node->value << " .\n";
            }
        }
    }

    void ShowForwardBackwards(){
        for (int i=0;i<=level;i++){
            Node *node = head->next[i];
            cout << "Level " << i << ": ";
            while (node != nullptr && node->next[i] != nullptr){
                cout << node->value << " -> ";
                node = node->next[i];
            }
            while (node != nullptr && node->prev[i] != head){
                cout << node->value << " <- ";
                node = node->prev[i];
            }
            if(node!=nullptr){
                cout << node->value << " .\n";
            }
        }
    }
};

#endif