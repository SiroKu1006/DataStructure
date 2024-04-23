#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <fstream>
#include "MatrixTerm.cpp"
#include "Stack.cpp"
using namespace std;

class Maze{
    private:
        int row,col,term;
        MatrixTerm *matrix;
        Stack *walked;
    public:
        Maze(int r,int c ,int t);
        void setCase(int c,int r,char v);
};

#endif