#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include <iostream>
#include <vector>
#include <string>
#include "MatrixTerm.h"
using namespace std;

class SparseMatrix {
    private:
	    int rows, cols, terms;
	    MatrixTerm *smArray;
    public:
        SparseMatrix(int r, int c, int t);
        SparseMatrix Transpose();
        SparseMatrix FastTranspose();
        void addTerm(int row, int col, int value,int i);
        void print();
};


#endif