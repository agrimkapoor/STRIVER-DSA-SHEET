// sieve of eratosthenes 

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n = 10;
    vector<int>nums(n+1,1);//initially sab prime hai
    for(int i=2;i<=10;i++){
        if(nums[i]==1){
            for(int j=2*i;j<=n;j+=i){
                nums[j]=0;
            }
        }
    }

    return 0;
}