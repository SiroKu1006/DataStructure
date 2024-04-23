#include "Stack.h"


Stack::Stack(int s){
    top = -1;
    max_size = s;
    ar = new MatrixTerm[s];
}

void Stack::push(MatrixTerm val){
    if (top == max_size-1){
        cout << "Stack is full" << "\n";
    }else{
        ar[++top] = val;
    }
}
MatrixTerm Stack::pop(){
    if (top == -1){
        cout << "Stack is empty" << "\n";
    }else{
        return ar[top--];
    }
}