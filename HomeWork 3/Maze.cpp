#include "Maze.h"

Maze::Maze(int r,int c ,int t){
    row = r;
    col = c;
    term = t;
    matrix = new MatrixTerm[t];
    walked = new Stack[t];
}

Maze::setCase(int c,int r ,char v){
    
}