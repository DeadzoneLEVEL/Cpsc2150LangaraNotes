#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "CircularList.h"
#ifndef ROUNDROBIN_H
#define ROUNDROBIN_H
/**
 * @brief An h file to implement round robin process scheduling
 * @author Gregory Bennett, 100384770
 * @date Friday, September 29th
 */

class RoundRobinProcessScheduler{
    private:
        int timeSlice;
        int items=0;
        CircularLinkedList processTime;
        struct info{
            int time;
            int id;
        };
        vector<info> results;
    public:
        void LoadFromFile(std::string file);
        void process();
        void showResults();
        void display();
};

/**
 * @brief A void method to load info from file into a
 * circular linked list
 * Time Complexity: O(n) with n being the amount of 
 * info being read as it loops through the entire file
 * @param file 
 */
void RoundRobinProcessScheduler::LoadFromFile(std::string file){
    std::ifstream fin;
    std::string line;
    fin.open(file);
    fin>>timeSlice;
    if(fin.fail()){
        std::cerr<<"FILE NOT FOUND\n";
        return;
    }
    
    while(getline(fin,line,',')){
        processTime.insert(stoi(line),items+1);
        items++;
    }
    fin.close();
    
}

/**
 * @brief A void method to loop through linked list and subtract timeSlice from each node,
 * once nodes data reaches 0 it is then removed from linked list and has its results stored
 * in results vector
 * Time Complexity:O(n^2) since not only does process loop through the linked list, but
 * the deleteNode(Node*) function called in  the method itself has a O(n)
 */
void RoundRobinProcessScheduler::process(){
    Node* current=processTime.getPointer()->next;
    int clock=0;
    
    while(!processTime.isEmpty()){
        current->data-=timeSlice;
        if(current->data<=0){
            Node*temp=current;
            if(!(current->next==current)){
                current=current->next;
            }
            clock+=temp->data+timeSlice;
            results.push_back({clock,temp->id});
            processTime.deleteNode(temp);
        }else{
            if(!(current->next==current)){
                current=current->next;
            }
            clock+=timeSlice;
        }
    }
    items=0;
}

/**
 * @brief A void method to print out toconsole/terminal when each process was completed
 * depending on the given int timeSlice
 * Time Complexity: O(n) as it loops through the vector results of size n
 */
void RoundRobinProcessScheduler::showResults(){
    double total=0;
    int ind=0;
    for(unsigned i=0;i<results.size();i++){
        total+=results[i].time;
        ind++;
        printf("p%d: %d\n",results[i].id,results[i].time);
    }
    printf("Average: %.2f\n",total/ind);
    results.clear();
}

/**
 * @brief A void method to print out the current data in the circular linked 
 * list to the console/terminal
 * Time Complexity: O(n) as it loops through the entire list of size n
 */
void RoundRobinProcessScheduler::display(){
    processTime.display();
}


#endif