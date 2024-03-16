#include "Graph.h"
#include <iostream>
#include <sstream>

// using namespace std;

int main(){
    Graph g("distances2.txt");
    std::cout<<"This is the current Graph ";
    g.ShowLocationInfo();
    // g.printNeighbors("vancouver");
    // g.testFindMin("vancouver");
    // g.testQueue();
    // g.testVector();
    // g.Djikstras("e","a");
    // g.showCopyInfo();
    std::string str;
    std::string listOfCities;
    std::cout<<"Enter the source location: ";
    std::cin>>str;
    std::cout<<"Enter the destination location(s): ";
    std::cin>>listOfCities;
    std::istringstream seperator(listOfCities);
    std::string results="";
    while(getline(seperator,results,',')){
        g.Djikstras(str,results);
        std::cout<<std::endl;
    }
    return 0;
}