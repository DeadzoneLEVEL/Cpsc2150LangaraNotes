#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <ctime>
#include <queue>
// using namespace std;

// class Edge{
// public:
//     // assume u and v are two vertices 
//     // vertices are zero-indexed
//     int u;
//     int v;

//     Edge(){
//         u = -1; // invalid vertex index
//         v = -1; // invalid vertex index
//     }

//     Edge(int _u, int _v){
//         u = _u;
//         v = _v;
//     }

//     const Edge& operator=(const Edge&rhs){
//         this->u=rhs.u;
//         this->v=rhs.v;
//         return *this;
//     }

//     friend std::ostream& operator<<(std::ostream &out,const Edge &e){
//         out<<"{"<<e.u<<","<<e.v<<"}";
//         return out;
//     }
//     bool operator==(const Edge&rhs){
//         bool control=true;
//         if(this->u!=rhs.u){
//             control=false;
//         }
//         if(this->v!=rhs.v){
//             control=false;
//         }
//         return control;
//     }

// };

class vertex {
    public:
        int u;
        int v;
        bool wall;
        vertex();
        vertex(int _u, int _v, bool _wall);
        const vertex& operator=(const vertex&rhs);
        friend std::ostream& operator<<(std::ostream &out,const vertex &e);
        bool operator==(const vertex &rhs);
};

vertex::vertex(){
    u=-1;
    v=-1;
    wall=false;
}

vertex::vertex(int _u, int _v, bool _wall) {
    u = _u;
    v = _v;
    wall = _wall;
}

const vertex& vertex::operator=(const vertex&rhs){
    this->u=rhs.u;
    this->v=rhs.v;
    this->wall=rhs.wall;
    return *this;
}

std::ostream& operator<<(std::ostream &out,const vertex &e){
    out<<"{"<<e.u<<","<<e.v<<":"<<std::boolalpha<<e.wall<<"}";
    return out;
}

bool vertex::operator==(const vertex &rhs){
    bool control=true;
    if(this->u!=rhs.u){
        control=false;
    }
    if(this->v!=rhs.v){
        control=false;
    }
    if(this->wall!=rhs.wall){
        control=false;
    }
    return control;
}

class graph{
    private:
        std::vector<vertex> vertices;
        std::vector<std::vector<vertex>> adjacencyList;
        // std::vector<Edge> edgeList;
        int width;
        int height;
        bool outOfBounds(int x,int y,int h,int w);
        void makeAdjacencyList(unsigned adjacencyMatrix[4][4],int h,int w);
        void makeVertices(unsigned adjacencyMatrix[4][4],int h,int w);
        void pathHelper(vertex current,vertex key,std::vector<vertex> &visited,std::vector<vertex>paths,bool &ret);
        bool vectExistInVect2(std::vector<vertex> vec,std::vector<vertex> vec2);
        bool existInVect(vertex val,std::vector<vertex> vec);
        void exploreGraph(vertex current,std::vector<vertex> &visited);
    public:
        graph();
        graph(unsigned adjacencyMatrix[4][4], int _height,int _width);
        void displayVertices();
        void displayAdjacencyList();
        bool pathFinder();
        bool pathFinder(vertex v1, vertex v2);
        bool isConnected();
        int countIslands();

};

graph::graph(){
}
graph::graph(unsigned adjacencyMatrix[4][4], int _height,int _width){
    // adjacencyMatrix has dimension n x n with zeroes along the main diagonal
    // assume row 0 is for vertex 0, row 1 is for vertex 1 and so on

    // TASKS: add methods to do the following:
    // build vertices, adjacencyList, edgeList using adjacencyMatrix.
    width=_width;
    height=_height;
    makeVertices(adjacencyMatrix,_height,_width);
    makeAdjacencyList(adjacencyMatrix,_height,_width);
}
bool graph::outOfBounds(int x,int y,int h,int w){
    if(x<0||x>=h||y<0||y>=w){
        return true;
    }else{
        return false;
    }
}

void graph::makeAdjacencyList(unsigned adjacencyMatrix[4][4],int h,int w){
    adjacencyList.resize(vertices.size());
    vertex tmp;
    int index = 0;
    for(int row=0;row<h;row++){
        for(int col=0;col<w;col++){
            if(!outOfBounds(row,col+1,h,w)){
                tmp=vertex(row,col+1,adjacencyMatrix[row][col+1]==0);
                adjacencyList[index].push_back(tmp);
            }
            if(!outOfBounds(row,col-1,h,w)){
                tmp=vertex(row,col-1,adjacencyMatrix[row][col-1]==0);
                adjacencyList[index].push_back(tmp);
            }
            if(!outOfBounds(row+1,col,h,w)){
                tmp=vertex(row+1,col,adjacencyMatrix[row+1][col]==0);
                adjacencyList[index].push_back(tmp);
            }
            if(!outOfBounds(row-1,col,h,w)){
                tmp=vertex(row-1,col,adjacencyMatrix[row-1][col]==0);
                adjacencyList[index].push_back(tmp);
            }

            // adjacencyList[row].push_back(vertex());
            index++;
        }
    }
    return;
}

void graph::makeVertices(unsigned adjacencyMatrix[3][4],int h,int w){
    // vertices.resize(n*n);
    vertex tmp;
    for (int row=0;row<h;row++) {
        for (int col=0;col<w;col++) {
            tmp=vertex(row,col,adjacencyMatrix[row][col]==0);
            vertices.push_back(tmp);
        }
    }
    return;
}

void graph::displayVertices() {
    std::cout<<"Vertices: \n";
    for (unsigned i=0;i<vertices.size();i++) {
        std::cout<<vertices[i]<<"\n";
    }
    std::cout<<"\n";
    return;
}

void graph::displayAdjacencyList() {
    std::cout<<"Adjancency List: \n";
    unsigned indexX=0,indexY=0;
    for (unsigned row=0;row<adjacencyList.size();row++) {
        std::cout<<"("<<indexX<<","<<indexY<<"):";
        for (unsigned col=0;col<adjacencyList[row].size();col++) {
            std::cout<<adjacencyList[row][col]<<" ";
        }
        std::cout<<"\n";
        indexY++;
        if(indexY==width){
            indexX++;
            indexY=0;
        }
    }
    return;
}

bool graph::pathFinder(){
    vertex start=vertices[0];
    vertex end=vertices[vertices.size()-1];
    return pathFinder(start,end);
}

bool graph::pathFinder(vertex v1, vertex v2){
    // returns the length of the path (number of edges) if there 
    //is a path from vertex v1 to vertex v2; otherwise returns 0
    std::vector<vertex> paths;
    std::vector<vertex> visited;
    bool ret=false;
    std::cout<<"{ ";
    pathHelper(v1,v2,visited,paths,ret);
    std::cout<<"}\n";
    // std::cout<<std::boolalpha<<control<<"\n";
    return ret;
}

void graph::pathHelper(vertex current,vertex key,std::vector<vertex> &visited,std::vector<vertex>paths,bool &ret){
    // std::cout<<current<<"\n";
    paths.push_back(current);
    if (current==key){
        ret=true;
        for(unsigned i=0;i<paths.size();i++){
            std::cout<<paths[i]<<" ";
        }
        return;
    }
    if(current.wall){
        paths.pop_back();
        return;
    }
    if(adjacencyList[(width*current.u)+current.v].size()==0){
        visited.push_back(current);
        paths.pop_back();
        return;
    }
    if(vectExistInVect2(adjacencyList[(width*current.u)+current.v],visited)){
        paths.pop_back();
        return;
    }
    visited.push_back(current);
    
    for(unsigned i=0;i<adjacencyList[(width*current.u)+current.v].size();i++){
        // std::cout<<"It got here\n";
        // std::cout<<"For "<<current.v<<":"<<std::boolalpha<<!existInVect(adjacencyList[current.u][i],visited);
        if(!existInVect(adjacencyList[(width*current.u)+current.v][i],visited)){
            // std::cout<<"For "<<(width*current.u)+current.v<<":"<<adjacencyList[(width*current.u)+current.v][i]<<"\n";
            pathHelper(adjacencyList[(width*current.u)+current.v][i],key,visited,paths,ret);
        }
    }
    paths.pop_back();
    return;
}

bool graph::vectExistInVect2(std::vector<vertex> vec,std::vector<vertex> vec2){
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

bool graph::existInVect(vertex val,std::vector<vertex> vec){
    bool control=false;
    for(unsigned i=0;i<vec.size();i++){
        if(vec[i]==val){
            control=true;
        }
    }
    return control;
}

bool graph::isConnected(){
    std::vector<vertex> visited;
    exploreGraph(vertices[0],visited);
    return visited.size()==vertices.size();
}

void graph::exploreGraph(vertex current,std::vector<vertex> &visited){
    if(adjacencyList[(this->width*current.u)+current.v].size()==0){
        visited.push_back(current);
        return;
    }
    
    visited.push_back(current);
    for(unsigned i=0;i<adjacencyList[(this->width*current.u)+current.v].size();i++){
        if(!existInVect(adjacencyList[(this->width*current.u)+current.v][i],visited)){
            exploreGraph(adjacencyList[(this->width*current.u)+current.v][i],visited);
        }
    }
    return;
}

int graph::countIslands(){
    unsigned islands=0,index=0;
    std::vector<vertex> visited;
    while(visited.size()!=vertices.size()){
        if(!existInVect(vertices[index],visited)){
            exploreGraph(vertices[index],visited);
            islands+=1;
        }
        index+=1;
    }
    return int(islands);
}


#endif