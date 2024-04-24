#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <fstream>
#include "MatrixTerm.h"
using namespace std;

template <class T>
class Stack{
    private:
        int max_size;
        int top;
        T* ar;
    public:
        Stack(int size);
        bool isEmpty();
        void pop();
        T pop();
};

#endif