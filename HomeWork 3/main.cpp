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
    bool flag = true;
    while (getline(cin, s)){
        row++;
        for (int i = 0; i < s.length(); i++){
            if (s[i] != ' '){
                a+=s[i];
                col++;
            }
        }
        a+="\n";
    }
    cout << a;
}