#include "Maze.h"

Maze::Maze(int r,int c ,int t){
    row = r;
    col = c;
    term = t;
    matrix = new MatrixTerm[t];
    walked = new Stack[t];
    index = 0;
}

void Maze::setCase(int c,int r ,char v){
    matrix[index].row = r;
    matrix[index].col = c;
    matrix[index].value = v;
    index++;
}

