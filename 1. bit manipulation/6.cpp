// binary exponentiation : to calculate pow (x,n) in logn time

#include <bits/stdc++.h>
using namespace std;

int f(int x,int n){
    if(n==0)return 1;

    if(n%2==0){
        return f(x*x,n/2);
    }
    else return x * f(x,n-1);
}

int main(){

    int x=2,n=21;
    cout<<f(x,n);
    
    return 0;
}