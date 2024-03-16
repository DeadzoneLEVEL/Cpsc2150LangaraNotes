#include <iostream>
#include "Graph.h"
using namespace std;

int main(){
    bool mat1[2][2] = { {0,1},
                        {1,0}
                        };

    bool mat2[4][4] = { {0,0,1,1},
                        {0,0,1,0},
                        {1,1,0,1},
                        {1,0,1,0}
                        };
    bool mat3[4][4]={
    {0,1,0,1},
    {0,0,0,1},
    {0,1,0,1},
    {1,0,1,0}};
    bool mat4[4][4]={
    {0,1,0,1},
    {1,0,1,0},
    {0,1,0,1},
    {1,0,1,0}};
    bool mat5[4][4]={
    {0,1,0,0},
    {0,0,1,0},
    {0,0,0,1},
    {0,0,0,0}};
    bool mat6[4][4]={
    {0,1,0,0},
    {1,0,0,1},
    {0,0,0,1},
    {0,1,1,0}};
    Graph g(mat2,4);
    g.ShowVertices();
    g.ShowAdjacencyList();
    g.ShowEdgeList();
    g.ShowNeighbors(2);
    int a=1,b=3;
    std::cout<<"Does "<<a<<" and "<<b<<" have an edge? ";
    std::cout<<std::boolalpha<<g.HasEdge(a,b)<<std::endl;
    g.ShowDegrees();
    a=0;
    b=2;
    std::cout<<"Length of path between "<<a<<" and "<<b<<" is: "<<g.Path(a,b)<<std::endl;
    g.ShowCycles();
    std::cout<<std::boolalpha<<g.IsDirected()<<std::endl;
    Graph g2(mat3,4);
    std::cout<<std::boolalpha<<g2.IsDirected()<<std::endl;
    Graph g3(mat4,4);
    std::cout<<std::boolalpha<<g3.HasCycle()<<std::endl;
    Graph g4(mat5,4);
    std::cout<<std::boolalpha<<g4.HasCycle()<<std::endl;
    g4.ShowCycles();
    Graph g3(mat6,4);
    std::cout<<g3.Path(0,2);
    return 0;
}
