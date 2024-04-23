#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <fstream>
#include "MatrixTerm.h"
using namespace std;

class Stack{
    private:
        int max_size = 128;
        int top;
        MatrixTerm *ar;
    public:
        Stack(int size);
        Stack():max_size(max_size),top(top),ar(ar){};
        void push(MatrixTerm val);
        MatrixTerm pop();
};

#endif