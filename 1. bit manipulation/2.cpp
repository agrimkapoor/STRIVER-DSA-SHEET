// printing the subsets of a vector using bitmasking

#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> v = {1,2,3};
    int n = v.size();

    for(int i = 0; i<(1<<n); i++){ // 1<<n is equal to 2^n
        for(int j = 0; j<n; j++){
            if(i & (1<<j)){ // if the jth bit is set in i, then include v[j] in the subset
                cout << v[j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}