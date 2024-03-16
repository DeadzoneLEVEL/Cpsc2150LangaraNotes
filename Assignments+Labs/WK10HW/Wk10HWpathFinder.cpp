#include <iostream>
#include "Graph.h"


int main(){
    // unsigned maze[4][4] = {
    //                 {1,1,1,1},
    //                 {0,1,0,1},
    //                 {0,1,0,1},
    //                 {0,1,1,1}
    //             };

    unsigned maze2[3][4]={
        {1,1,1,1},
        {0,0,1,0},
        {0,0,1,1}
    };
    // unsigned maze3[4][3]={
    //     {1,1,1},
    //     {0,0,1},
    //     {0,0,1},
    //     {0,0,1}
    // };
    Graph temp(maze2,3,4);
    // Graph temp(maze3,4,3);
    std::cout << "vertex:\n";
    temp.displayVertices();
    temp.displayAdjacencyList();
    std::cout<<"PathFinder:\n";
    bool control=temp.pathFinder();
    std::cout<<std::boolalpha<<control<<std::endl;

    // Graph test(maze, 4,4);
    // std::cout << "vertex:\n";
    // test.displayVertices();
    // test.displayAdjacencyList();

    // std::cout << "adj list:\n";
    // test.displayAdjacencyList();
    // walls are 0
    // paths are numbers that arent 0
    
    // starting point at 0, end point at 1
    // return 1 if it is doable, return 0 if not doable

    /**
     * @brief Given a maze (n x n 2D array of unsigned ints) where paths 
     * are marked with non-zero numbers and walls are 
     * marked with zeroes; output true/1 if there exists 
     * a path from the top-left corner (row 0, column 0) to the 
     * bottom-right corner (row n-1, column n-1) of the maze; if no path 
     * exists then output false/0.
     * 
     * In the maze shown above (4 x 4) there are 2 such paths.
     * 
     * If the top-left corner cell contains a zero in any maze then there 
     * can be no paths in that maze.     * 
     * 
     * Formulate the problem as a graph (vertices, edges).
     * Use graph algorithms (bfs, dfs) to solve the problem.
     * 
     * Thoroughly test your code - generate random mazes to validate your 
     * code. Try other values for n. You may limit your tests to unsigned 
     * int type square 2d arrays.
     * 
     * Feel free to use any Graph related code provided on D2L. 
     */
    return 0;
}