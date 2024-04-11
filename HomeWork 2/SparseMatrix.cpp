#include <bits/stdc++.h>
#include "SparseMatrix.h"
using namespace std;

SparseMatrix::SparseMatrix(int r, int c, int t) {
	rows = r;
	cols = c;
    terms = t;
	smArray = new MatrixTerm[t];
}
SparseMatrix SparseMatrix::Transpose(){
    SparseMatrix b(rows, cols, terms);
    if (terms > 0){
        int currentB = 0;
        for (int c = 0; c < cols; c++)
            for (int i = 0; i < terms; i++)
                if (smArray[i].col == c) {
                    b.smArray[currentB].row = c;
                    b.smArray[currentB].col = smArray[i].row;
                    b.smArray[currentB++].value = smArray[i].value;
                }
    }
    return b;
    
}
SparseMatrix SparseMatrix::FastTranspose(){
    SparseMatrix b(cols, rows, terms);
    if (terms>0){
        int *rowSize = new int[cols];
        int *rowStart = new int[cols];
        fill(rowSize,rowSize+cols,0);
        for (int i = 0; i < terms; i++) {
            rowSize[smArray[i].col]++;
        }
        rowStart[0] = 0;
        for (int i = 1 ; i < cols ; i++) rowStart[i] = rowStart[i-1] + rowSize[i-1];
        for (int i = 0 ; i < terms ; i++){
            int j = rowStart[smArray[i].col];
            b.smArray[j].row= smArray[i].col;
            b.smArray[j].col= smArray[i].row;
            b.smArray[j].value = smArray[i].value;
            rowStart[smArray[i].col]++;
        }
        delete [] rowSize;
        delete [] rowStart;
    }
    return b;
    
}

void SparseMatrix::addTerm(int row,int col,int value,int i){
    smArray[i].row = row;
    smArray[i].col = col;
    smArray[i].value = value;
}

void SparseMatrix::print(){
    for (int i = 0; i < terms; i++){
        cout << smArray[i].row << " " << smArray[i].col << " " << smArray[i].value << "\n";
    }
    
}