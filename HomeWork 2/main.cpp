#include<bits/stdc++.h>
#include "SparseMatrix.cpp"
#include "MatrixTerm.cpp"
using namespace std;



int main(){
    // string filename;
    // ifstream inFile;
    // while(true){
    //     cout << "Enter the filename:\n";
    //     // cin >> filename;
    //     inFile.open("TestData/721_850.in");
    //     if (inFile) break;
    //     cout << "File not found. Please enter again.\n";
    // }
    int n,m ;
    cin >> n >> m;
    vector<MatrixTerm> terms;
    vector<vector<int>> A(n,vector<int>(m));
    int row,col,val;
    while(cin >> row >> col >> val){
        A[row][col] = val;
        MatrixTerm term(row, col, val);
        terms.push_back(term);
    };
    SparseMatrix A_Matrix(n,m,terms.size());

    for (int i = 0; i < terms.size(); i++){
        A_Matrix.addTerm(terms[i].GetRow(), terms[i].GetCol(), terms[i].GetValue(),i);
    }

    auto start = chrono::high_resolution_clock::now();
    vector<vector<int>> B(m,vector<int>(n));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            B[i][j] = A[j][i];
        } 
    };
    auto end = chrono::high_resolution_clock::now();
    auto time2D = chrono::duration_cast<chrono::microseconds>(end - start).count();


    start = chrono::high_resolution_clock::now();
    SparseMatrix B_Matrix = A_Matrix.Transpose();
    end = chrono::high_resolution_clock::now();

    auto timeTran = chrono::duration_cast<chrono::microseconds>(end - start).count();
    
    start = chrono::high_resolution_clock::now();
    SparseMatrix C_Matrix= A_Matrix.FastTranspose();
    
    end = chrono::high_resolution_clock::now();
    auto timeFaTran = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Case 2-dimensional array :\n";

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << i << " " << j << " "<< B[i][j] << "\n";
        }
        
    }
    cout << "Case Transpose :\n";
    B_Matrix.print();
    cout << "Case FastTranspose :\n";
    C_Matrix.print();
    cout << " 2-dimensional array use " << time2D/1000.0 << "ms\n" ;
    cout << "Transpose use " << timeTran/1000.0 << "ms\n" ;
    cout << "FastTranspose use " << timeFaTran/1000.0 << "ms\n" ; 
};

