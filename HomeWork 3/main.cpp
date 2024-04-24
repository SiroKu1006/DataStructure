#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <fstream>
using namespace std;

int move_case[8][2] = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
char walk_steps[8] = {'|','/','-','\\','|','/','-','\\'};
class arr{
    public:
        int col,row;
        arr (int r,int c){
            this->col = c;
            this->row = r;
        }
        arr (){
            col = -1;
            row = -1;
        }
};

template <class T>
class Stack{
    private:
        int max_size;
        int top;
        T* ar;
    public:
        Stack(int s){
            top = -1;
            max_size = s;
            ar = new T[s];
        };
        ~Stack(){
            delete[] ar;
        };
        bool isEmpty(){
            return top == -1;
        };
        void pop(){
            if (!isEmpty()){
                top--;
                return;
            }
            cout << "Is Underflow\n";
        };
        T Top(){
            if (!isEmpty()){
                return ar[top--];
            }
            cout << "Is Empty\n";
            return -1;
        };
        void push(T val){
            if (top < max_size-1){
                ar[++top] = val;
                return;
            }
            cout << "Is Overflow\n";
    };
};
void DFS(char** maze ,int row ,int col ,int st_r,int st_c , int ed_r ,int ed_c){
    Stack<arr> stack((row+2)*(col+2));
    stack.push(arr(st_r,st_c));
    while(!stack.isEmpty()){
        next:
        arr temp = stack.Top();
        if (st_r == ed_r && st_c == ed_c){
            cout << "Found\n";
            return;
        }
        for (int i = 0; i < 8; i++){
            int mv_r = temp.row + move_case[i][0];
            int mv_c = temp.col + move_case[i][1];
                if(maze[mv_r][mv_c] == '0'){
                    stack.push(arr(mv_r,mv_c));
                    maze[mv_r][mv_c] = walk_steps[i];
                    goto next;
            }
        }
        maze[temp.row][temp.col] = 'b';
        stack.pop();
    }
    cout << "Not Found\n";
    return;
}
int main(){

    system("pause");
}