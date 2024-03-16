#ifndef GRAPH
#define GRAPH

#include <iostream>

#include <queue>
#include <stack>

using namespace std;

class vertex {
    public:
        int x;
        int y;
        bool isWall;
        
        vertex(int _x, int _y, int _isWall) {
            x = _x;
            y = _y;
            isWall = _isWall;
        }
        bool operator==(const vertex &rhs){
            bool control=true;
            if(this->x!=rhs.x){
                control=false;
            }
            if(this->y!=rhs.y){
                control=false;
            }
            if(this->isWall!=rhs.isWall){
                control=false;
            }
            return control;
        }
};

class graph {
    private:
        vector<vector<int>> vertices;
        vector<vector<vector<vertex>>> adjacencyList;

        bool isValidPath(int x, int y, int size) {
            if (x < 0 or x >= size) return false;
            if (y < 0 or y >= size) return false;

            return vertices[x][y];
        }
        
    public:
        graph() {}

        graph(unsigned int matrix[][4], int n) {
            createVertices(matrix, n);
            createAdjacencyList();
        }

        void createVertices(unsigned int matrix[][4], int n) {
            vertices.resize(n);
            for (int y = 0; y < n; y++) {
                vertices.at(y).resize(n);
                for (int x = 0; x < n; x++) {
                    vertices.at(y)[x] = matrix[y][x];
                }
            }
        }

        void createAdjacencyList() {
            adjacencyList.resize(vertices.size());
            for (int y = 0; y < vertices.size(); y++) {
                adjacencyList.at(y).resize(vertices.at(y).size());
                for (int x = 0; x < vertices[y].size(); x++) {
                    int size = vertices[y].size();

                    if (isValidPath(y + 1, x, size)) { // bottom
                        adjacencyList[y][x].push_back(
                            vertex(x, y + 1, vertices[y + 1][x] != 0)
                        );
                    }

                    if (isValidPath(y - 1, x, size)) { // top
                        adjacencyList[y][x].push_back(
                            vertex(x, y - 1, vertices[y - 1][x] != 0)
                        );
                    }

                    if (isValidPath(y, x + 1, size)) { // right
                        adjacencyList[y][x].push_back(
                            vertex(x + 1, y, vertices[y][x + 1] != 0)
                        );
                    }

                    if (isValidPath(y, x - 1, size)) { // left
                        adjacencyList[y][x].push_back(
                            vertex(x - 1, y, vertices[y][x - 1] != 0)
                        );
                    }
                }
            }
        }

        void displayVertices() {
            for (int y = 0; y < vertices.size(); y++) {
                for (int x = 0; x < vertices[y].size(); x++) {
                    cout << vertices[y][x] << " ";
                }
                cout << endl;
            }
        }

        void displayAdjacencyList() {
            for (int y = 0; y < adjacencyList.size(); y++) {
                for (int x = 0; x < adjacencyList[y].size(); x++) {
                    cout << "[" << x << " " << y << "]: ";
                    for (int z = 0; z < adjacencyList[y][x].size(); z++) {
                        vertex vertice = adjacencyList[y][x].at(z);
                        cout << "(" << vertice.x << ", " << vertice.y << ")" << (z < adjacencyList[y][x].size() - 1? " | " : "");
                    }
                    cout << endl;
                }
            }
        }
        void pathFinder(){

        }
        void pathFinder(int current,std::vector<int> visited,int size,bool &key){
            
            return;
        }
        bool existInVect(vertex val,std::vector<vertex> vec){
            bool control=false;
            for(unsigned i=0;i<vec.size();i++){
                if(vec[i]==val){
                    control=true;
                }
            }
            return control;
        }
};

#endif