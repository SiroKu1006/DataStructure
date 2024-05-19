#include <iostream>
using namespace std;

long long k(int n){
    if(n==1) return 1;
    return k(n-1)+n;
}

int main(){
    int n;
    cin>>n;
    cout<<k(n);
    system("pause");
}