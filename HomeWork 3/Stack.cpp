#include "Stack.h"

Stack::Stack(int s){
    top = -1;
    max_size = s;
    ar = new T[s];
}
Stack::~Stack(){
    delete[] ar;
}

vou