#ifndef MATRIXTERM_H
#define MATRIXTERM_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MatrixTerm {
    friend class Stack;
    private:
        int row, col, value;
    public:
        MatrixTerm() : row(0), col(0), value(0){}
        MatrixTerm(int row, int col, int value) : row(row), col(col), value(value) {}
        int GetRow();
        int GetCol();
        int GetValue();
};


#endif