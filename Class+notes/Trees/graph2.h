#ifndef GRAPH2_H
#define GRAPH2_H

#include <iostream>
#include <vector>
#include <ctime>
#include <queue>
// using namespace std;

class Edge{
public:
    // assume u and v are two vertices 
    // vertices are zero-indexed
    int u;
    int v;

    Edge(){
        u = -1; // invalid vertex index
        v = -1; // invalid vertex index
    }

    Edge(int _u, int _v){
        u = _u;
        v = _v;
    }

    const Edge& operator=(const Edge&rhs){
        this->u=rhs.u;
        this->v=rhs.v;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream &out,const Edge &e){
        out<<"{"<<e.u<<","<<e.v<<"}";
        return out;
    }
    bool operator==(const Edge&rhs){
        bool control=true;
        if(this->u!=rhs.u){
            control=false;
        }
        if(this->v!=rhs.v){
            control=false;
        }
        return control;
    }

};

class graph2{
private:
    std::vector<int> vertices;
    std::vector<std::vector<int>> adjacencyList;
    std::vector<Edge> edgeList;
    int pathHelper(int current,int key,std::vector<int> &visited,bool &found);
    bool vectExistInVect2(std::vector<int> vec,std::vector<int> vec2);
    bool existInVect(int val,std::vector<int> vec);
    void HasCycleHelper(int current,std::vector<int> visited,bool &key);
    void showCycleHelper(int current,std::vector<int> visited,std::vector<int>paths);
    void exploreGraph(int current,std::vector<int> &visited);
public:
    graph2();
    graph2(bool adjacencyMatrix[4][4], int n);
    void BuildEdgeList(int n);
    void BuildAdjacencyList(bool adjacencyMatrix[4][4], int n);
    void BuildVertices(int n);
    void ShowVertices();
    void ShowAdjacencyList();
    void ShowEdgeList();
    int VertexCount();
    int EdgeCount();
    void ShowNeighbors(int v);
    int Degree(int v);
    bool IsDirected();
    void ShowDegrees();
    bool HasEdge(int v1, int v2);
    int Path(int v1, int v2);
    bool HasCycle();
    void ShowCycles();
    bool isConnected();
};

graph2::graph2(){
}

graph2::graph2(bool adjacencyMatrix[4][4], int n){
    // adjacencyMatrix has dimension n x n with zeroes along the main diagonal
    // assume row 0 is for vertex 0, row 1 is for vertex 1 and so on

    // TASKS: add methods to do the following:
    // build vertices, adjacencyList, edgeList using adjacencyMatrix.
    BuildAdjacencyList(adjacencyMatrix,n);
    BuildVertices(n);
    BuildEdgeList(n);
}

void graph2::BuildEdgeList(int n){
    Edge temp;
    for(unsigned row=0;row<adjacencyList.size();row++){
        for(unsigned column=0;column<adjacencyList[row].size();column++){
            temp=Edge(row,adjacencyList[row][column]);
            edgeList.push_back(temp);
        }
    }
}

void graph2::BuildAdjacencyList(bool adjacencyMatrix[4][4], int n){
    adjacencyList.resize(n);
    //loop through this
    for(int row=0;row<n;row++){
        for(int column=0;column<n;column++){
            if(row!=column){
                if(adjacencyMatrix[row][column]){
                    adjacencyList[row].push_back(column);
                }
            }
        }
    }
}

void graph2::BuildVertices(int n){
    for(int i=0;i<n;i++){
        vertices.push_back(i);
    }
}

void graph2::ShowVertices(){
    // display all vertices
    std::cout<<"Vertices: ";
    for(unsigned i=0;i<vertices.size();i++){
        std::cout<<vertices[i]<<" ";
    }
    std::cout<<"\n";
}

void graph2::ShowAdjacencyList(){
    // display adjacency list
    std::cout<<"Adjacency List: \n";
    for(unsigned row=0;row<adjacencyList.size();row++){
        std::cout<<"Vertices "<<row<<":";
        for(unsigned column=0;column<adjacencyList[row].size();column++){
            std::cout<<adjacencyList[row][column]<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
}

void graph2::ShowEdgeList(){
    // display edge list
    std::cout<<"Edge List: \n";
    for(unsigned col=0;col<edgeList.size()-1;col++){
        std::cout<<edgeList[col]<<",";
    }
    std::cout<<edgeList[edgeList.size()-1];
    std::cout<<"\n";
}

int graph2::VertexCount(){
    // returns the number of vertices in the graph
    return (int)vertices.size();
}

int graph2::EdgeCount(){
    // returns the number of edges in the graph
    return (int)edgeList.size();
}

void graph2::ShowNeighbors(int v){
    // display neighbors of vertex v
    std::cout<<"Neighbors of "<<v<<":\n{ ";
    for(unsigned i=0;i<adjacencyList[v].size();i++){
        std::cout<<adjacencyList[v][i]<<" ";
    }
    std::cout<<"}\n";
}

int graph2::Degree(int v){
    // return the degree of vertex v
    return (int)adjacencyList[v].size();
}

bool graph2::IsDirected(){
    // returns true if the graph is directed; false otherwise
    bool control2;
    Edge temp;
    for(unsigned i=0;i<edgeList.size();i++){
        temp=Edge(edgeList[i].v,edgeList[i].u);
        control2=false;
        for(unsigned j=0;j<edgeList.size();j++){
            if(temp==edgeList[j]&&i!=j){
                control2=true;
                break;
            }
        }
        if(control2==false){
            return true;
        }
    }
    return false;
}

void graph2::ShowDegrees(){
    // display degrees of all vertices
    std::cout<<"Degrees of all vertices\n";
    for(unsigned i=0;i<vertices.size();i++){
        std::cout<<"Degree of vertice "<<vertices[i]<<":";
        std::cout<<Degree(vertices[i])<<"\n";
    }
    std::cout<<"\n";
}

bool graph2::HasEdge(int v1, int v2){
    // returns true if there is an edge between vertices v1 n v2; false otherwise
    bool control=false;
    for(unsigned i=0;i<adjacencyList[v1].size();i++){
        if(adjacencyList[v1][i]==v2){
            control=true;
            break;
        }
    }
    if(!control){
        for(unsigned i=0;i<adjacencyList[v2].size();i++){
            if(adjacencyList[v2][i]==v1){
                control=true;
                break;
            }
        }
    }
    return control;
}

int graph2::Path(int v1, int v2){
    // returns the length of the path (number of edges) if there 
    //is a path from vertex v1 to vertex v2; otherwise returns 0
    std::vector<int> visited;
    bool control=false;
    int ret=pathHelper(v1,v2,visited,control);
    // std::cout<<std::boolalpha<<control<<"\n";
    return ret;
}
int graph2::pathHelper(int current,int key,std::vector<int> &visited,bool &found){
    if (current==key){
        found=true;
        return 0;
    } 
    visited.push_back(current);
    if(adjacencyList[current].size()==0){
        return 0;
    }
    if(vectExistInVect2(adjacencyList[current],visited)){
        return 0;
    }
    int p=0;
    for(unsigned i=0;i<adjacencyList[current].size();i++){
        if(!existInVect(adjacencyList[current][i],visited)){
            p=pathHelper(adjacencyList[current][i],key,visited,found);
            if(found){
                return p+1;
            }
        }
    }
    return 0;
}

bool graph2::vectExistInVect2(std::vector<int> vec,std::vector<int> vec2){
    bool control=true,control2;
    for(unsigned i=0;i<vec.size();i++){
        control2=false;
        for(unsigned j=0;j<vec2.size();j++){
            if(vec[i]==vec2[j]){
                control2=true;
            }
        }
        if(control2==false){
            control=false;
        }
    }
    return control;
}

bool graph2::existInVect(int val,std::vector<int> vec){
    bool control=false;
    for(unsigned i=0;i<vec.size();i++){
        if(vec[i]==val){
            control=true;
        }
    }
    return control;
}


bool graph2::HasCycle(){
    // return true if graph has a cycle (starting from a node we 
    //follow edges to return back to the same vertex); false otherwise
    std::vector<int> visited;
    bool ret=false;
    HasCycleHelper(vertices[0],visited,ret);
    return ret;
}

void graph2::HasCycleHelper(int current,std::vector<int> visited,bool &key){
    if(existInVect(current,visited)){
        key=true;
        return;
    }
    visited.push_back(current);
    for(unsigned i=0;i<adjacencyList[current].size();i++){
        HasCycleHelper(adjacencyList[current][i],visited,key);
    }
    return;
}

void graph2::ShowCycles(){
    // displays all cycles (if any)
    // each cycle should begin and end with the same vertex
    std::vector<int> visited;
    std::vector<int> paths;
    showCycleHelper(vertices[0],visited,paths);
}

void graph2::showCycleHelper(int current,std::vector<int> visited,std::vector<int>paths){
    paths.push_back(current);
    if(adjacencyList[current].size()==0){
        visited.push_back(current);
        paths.pop_back();
        return;
    }
    if(existInVect(current,visited)){
        bool control=false;
        std::cout<<"{ ";
        for(unsigned i=0;i<paths.size();i++){
            if(paths[i]==current){
                control=true;
            }
            if(control){
                std::cout<<paths[i]<<" ";
            }
        }
        std::cout<<"}\n";
        paths.pop_back();
        return;
    }
    visited.push_back(current);
    for(unsigned i=0;i<adjacencyList[current].size();i++){
        showCycleHelper(adjacencyList[current][i],visited,paths);
    }
    paths.pop_back();
    return;
}

bool graph2::isConnected(){
    std::vector<int> visited;
    exploreGraph(vertices[0],visited);
    return visited.size()==vertices.size();
}

void graph2::exploreGraph(int current,std::vector<int> &visited){
    if(adjacencyList[current].size()==0){
        visited.push_back(current);
        return;
    }
    visited.push_back(current);
    for(unsigned i=0;i<adjacencyList[current].size();i++){
        if(!existInVect(adjacencyList[current][i],visited)){
            exploreGraph(adjacencyList[current][i],visited);
        }
    }
    return;
}


#endif