#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <fstream>
#include "MatrixTerm.h"
#include "Stack.h"
using namespace std;

class Maze{
    private:
        int row,col,term,index;
        MatrixTerm *matrix;
        Stack *walked;
    public:
        Maze(int r,int c ,int t);
        void setCase(int c,int r,char v);
};

#endif