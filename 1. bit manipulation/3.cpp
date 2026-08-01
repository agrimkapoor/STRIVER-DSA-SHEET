// xor of numbers in given range [L,R]

#include <bits/stdc++.h>
using namespace std;



int main(){
    int L = 3, R = 9;

    //Method 1: Brute force approach
    int ans = 0;    
    for(int i = L; i<=R; i++){
        ans ^= i;
    }
    cout<< ans<<endl;

    //Method 2: Using the property of xor

    auto xorUpto = [](int n){
        if(n%4 == 0) return n;
        if(n%4 == 1) return 1;
        if(n%4 == 2) return n+1;
        return 0;
    };//ye lambda function hai 

    int ans2 = xorUpto(R) ^ xorUpto(L-1);
    cout << ans2 << endl;
    return 0;
}