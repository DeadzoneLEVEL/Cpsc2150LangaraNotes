#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <climits>
#include <stack>
using namespace std;

class Vertex
{
public:
    string name; // name of current location
    map<string, int> neighbors; // Neighboring locations and their distances
    
    Vertex()
    {
        name = "n/a";
    }

    void AddNeighbor(string n, int d)
    {
        // add a neighbor (with name n and distance d) to neighbors
        neighbors.insert({n,d});
    }
};

class Graph
{
private:
    map<string, Vertex> locations; // all cities and their neighbors (i.e. adjacencies) in the graph    
    
public:
    Graph()
    {
    }

    Graph(string file = "distances.txt"){
        if(file == ""){
            return;
        }

        // Read road network data from a file
        ifstream inputFile(file);
        if (!inputFile) {
            cout << "Error: Unable to open input file." << endl;
            return;
        }

        // Parse the input file
        string sourceLocation, destLocation;
        int distance;
        while (inputFile >> sourceLocation >> destLocation >> distance) {
            locations[sourceLocation].name = sourceLocation;
            locations[destLocation].name = destLocation;
            locations[sourceLocation].neighbors[destLocation] = distance;
        }
        inputFile.close();
    }

    void ShowLocationInfo(){
        cout << "Locations:" << endl;
        for (const auto& pair : locations) {
            cout << pair.first << ": ";
            for (const auto& neighbor : pair.second.neighbors) {
                cout << neighbor.first << "(" << neighbor.second << "), ";
            }
            cout << endl;
        }        
    }

    void Djikstras(std::string str,std::string str2){
        auto it=locations.find(str);
        auto it2=locations.find(str2);
        if(str==str2){
            std::cout<<"Shortest Route from "<<str<<" to "<<str2<<":\n";
            std::cout<<"Distance: 0 kilometers\n";
            std::cout<<"Route: "<<str<<"->"<<str2<<"\n";
        }else if(it!=locations.end()&&it2!=locations.end()){
            std::cout<<"Shortest Route from "<<str<<" to "<<str2<<":\n";
            DjikstrasHelper(it->second,it2->second);
        }else{
            std::cout<<"One of "<<str<<" or "<<str2<<" not found...\n";
        }
        return;
    }

    void printNeighbors(std::string str){
        auto tmp=locations.find(str);
        for(auto it=tmp->second.neighbors.begin();it!=tmp->second.neighbors.end();++it){
            std::cout<<it->first<<","<<it->second<<"\n";            
        }
    }
    void showCopyInfo(){
        map<string, int> distances;
        map<string,string> prev;
        auto it=locations.begin();
        while(it!=locations.end()){
            prev.insert({it->first,""});
            distances.insert({it->first,INT_MAX});
            ++it;
        }
        std::cout<<"Distances:\n";
        for (const auto& pair : distances) {
            std::cout<<pair.first << ": ";
            std::cout<<pair.second;
            std::cout<<std::endl;
        }   
        std::cout<<"previous:\n";
        for (const auto& pair : prev) {
            std::cout<<pair.first << ": ";
            std::cout<<pair.second;
            std::cout<<std::endl;
        } 
    }


    void testQueue(){
        auto comp = [](std::pair<Vertex,int> left, std::pair<Vertex,int> right) { 
            return left.second < right.second; 
        };
        std::priority_queue<std::pair<Vertex,int>, std::vector<std::pair<Vertex,int>>, decltype(comp)> pq(comp);
        // std::priority_queue<std::pair<Vertex,int>, std::vector<std::pair<Vertex,int>>> pq;
        auto it=locations.begin();
        while(it!=locations.end()){
            pq.push({it->second,INT_MAX});
            ++it;
        }
        while(!pq.empty()){
            std::cout<<pq.top().first.name<<"\n";
            pq.pop();
        }
    }

    void DjikstrasHelper(Vertex src,Vertex end){
        std::map<string, int> distances;
        std::map<string,string> prev;
        std::map<string,bool> visited;
        bool control=false;
        auto comp = [](std::pair<Vertex,int> left, std::pair<Vertex,int> right) { 
            return left.second > right.second; 
        };
        std::priority_queue<std::pair<Vertex,int>, std::vector<std::pair<Vertex,int>>, decltype(comp)> pq(comp);
        auto it=locations.begin();
        while(it!=locations.end()){
            visited.insert({it->first,false});
            prev.insert({it->first,""});
            distances.insert({it->first,INT_MAX});
            ++it;
        }
        pq.push({src,0});
        distances[src.name]=0;
        while(!pq.empty()){
            auto temp=pq.top();
            int u=temp.second;
            pq.pop();
            visited[temp.first.name]=true;
            for(const auto& neighbor:temp.first.neighbors){
                if(visited[neighbor.first]==false){
                    int alt=u+neighbor.second;
                    if(alt<distances[neighbor.first]){
                        if(locations[neighbor.first].name==end.name){
                            control=true;
                        }
                        pq.push({locations[neighbor.first],alt});
                        distances[neighbor.first]=alt;
                        prev[neighbor.first]=temp.first.name;
                    }
                }
            }
        }
        if(control){
            std::cout<<"Distance: "<<distances[end.name]<<" kilometers\n";
            std::vector<std::string>path;
            std::cout<<"Route: ";
            string current=end.name;
            path.push_back(current);
            // std::cout<<"*End location*"<<current<<"<-";
            while(current!=src.name){
                current=prev[current];
                path.push_back(current);
            }
            reverse(path.begin(),path.end());
            for(unsigned i=0;i<path.size()-1;i++){
                std::cout<<path[i]<<"->";
            }
            std::cout<<path[path.size()-1]<<"\n";

        }else{
            std::cout<<"No route exists for the given locations.\n";
        }
    }
};

#endif