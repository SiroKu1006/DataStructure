#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <fstream>
#include "Maze.cpp"
using namespace std;

int main(){
    int col,row;
    string s,a;
    char c;
    bool flag = true;
    Maze maze(0,0,0);
    while (getline(cin, s)){
        row++;
        for (int i = 1; i <= s.length(); i++){
            if (row == 1){
                for (int i = 0; i <= s.length()+1; i++){
                    maze.setCase(0,i,'W');
                }
                
            }
            else if (s[i-1] != ' '){
                c = s[i-1];
                maze.setCase(row,i,c);
            }
        }
        col = s.length()+1;
    }

    cout << a;
}