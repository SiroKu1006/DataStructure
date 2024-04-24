#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <fstream>
#include <algorithm>
using namespace std;

int move_case[8][2] = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
char walk_steps[8] = {'-','\\','|','/','-','\\','|','/'};
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
            // cout << top <<":top\n";
            if (!isEmpty()){
                top--;
                return;
            }
            cout << "Is Underflow\n";
        };
        T t_top(){
            if (!isEmpty()){
                return ar[top];
            }
            cout << "Is Empty\n";
            return T();
        };
        void push(T val){
            if (top < max_size-1){
                ar[++top] = val;
                // cout << top <<":top\n";
                return;
            }
            cout << "Is Overflow\n";
    };
};
bool DFS(char** maze ,int row ,int col ,int st_r,int st_c , int ed_r ,int ed_c){
    Stack<arr> stack((row+2)*(col+2));
    stack.push(arr(st_r,st_c));
    while(!stack.isEmpty()){
        next:
        arr temp = stack.t_top();
        // cout<< temp.row << " " << temp.col << "\n" ;
        if (temp.row == ed_r && temp.col == ed_c){
            // cout << "Found\n";
            return true;
        }
        // for (int i = 0; i < row; i++){
        //     for (int j = 0; j < col; j++){
        //         cout << maze[i+1][j+1];
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
        for (int i = 0; i < 8; i++){
            int mv_r = temp.row + move_case[i][0];
            int mv_c = temp.col + move_case[i][1];
                if(maze[mv_r][mv_c] == '0'){
                    stack.push(arr(mv_r,mv_c));
                    maze[mv_r][mv_c] = walk_steps[i];
                    // cout << walk_steps[i] << "\n";
                    goto next;
            }
        }
        maze[temp.row][temp.col] = 'b';
        stack.pop();
    }
    cout << "Not Found\n";
    return false;
}
int main(){
    // freopen("testcase/test1.in", "r", stdin);
    freopen("output/t3.out", "w", stdout);
    string s,cas;
    getline(cin,s);
    // cout << "p1\n";
    int col = s.length()/2+1;
    // cout << row << "\n";
    cas += s+ " ";
    while(cin.peek() != '\n' && getline(cin,s)){
        cas += s+ " ";
        cin.sync();
    }
    // cout << "p2\n";
    int row = cas.length()/col/2;
    // cout << cas << "\n";
    s = "";
    for (int i = 0; i < int(cas.length()); i++){
        if (cas[i] != ' '){
            s += cas[i];
        }
    }
    // cout << "p3\n";
    char** maze = new char*[row+2];
    for (int i = 0; i < row+2; i++){
        maze[i] = new char[col+2];
    }
    // cout << "p4\n";
    int st_r,st_c,ed_r,ed_c;
    for (int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            maze[i+1][j+1] = s[i*col+j];
        }
    }
    for (int i = 1; i <=row; i++) {
        for (int j = 1; j <=col; j++) {
            if(maze[i][j] == 's')
            {
                st_r = i;
                st_c = j;
            }
        }
    }
    for (int i = 1; i <=row; i++) {
        for (int j = 1; j <=col; j++) {
            if(maze[i][j] == 'e')
            {
                ed_r = i;
                ed_c = j;
            }
        }
    }
    char** old_maze = new char*[row+2];
    for (int i = 0; i < row+2; i++){
        old_maze[i] = new char[col+2];
    }
    for (int i = 0; i < row+2; i++){
        for (int j = 0; j < col+2; j++){
            old_maze[i][j] = maze[i][j];
        }
    }
    maze[st_r][st_c] = '0';
    maze[ed_r][ed_c] = '0';
    // cout <<  "st:" << st_r << " " << st_c << "\n" <<  "ed:" << ed_r << " " << ed_c << "\n";
    char ck[] = {'-','\\','|','/'};
    if (DFS(maze,row,col,st_r,st_c,ed_r,ed_c)){
        maze[st_r][st_c] = 's';
        maze[ed_r][ed_c] = 'e';
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                // cout << maze[i+1][j+1] << " ";
                if(find(ck,ck+4,maze[i+1][j+1]) != ck+4){

                    cout << maze[i+1][j+1] << " ";
                }
                else{
                    cout << old_maze[i+1][j+1]<< " ";
                }
            }
            cout << "\n";
        }
    }
    // cout << "Done\n";
    
    
}