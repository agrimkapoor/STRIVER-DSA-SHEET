//lambda function in c++ is a function without a name

#include <bits/stdc++.h>
using namespace std;

int main(){

    auto add = [](int a, int b){ // lambda function to add two numbers
        return a+b;
    };

    cout << add(2,3) << endl; // prints 5


    // [] ye hota hai capture clause which is used to capture variables from the surrounding scope. It can be empty, or it can contain variables to capture by value or by reference.

    /*
    []	kuch bhi capture nahi karo
    [x]	x ko by value capture karo (copy)
    [&x]	x ko by reference capture karo
    [=]	sab outer variables by value capture karo
    [&]	sab outer variables by reference capture karo
    [x, &y]	x by value, y by reference
    */

    //custom sort comparator

    vector<pair<int,int>> v = {{1,2},{3,4},{5,6},{7,8}};

    sort(v.begin(), v.end(), [](pair<int,int>&a, pair<int,int>&b){ // lambda function to sort pairs based on the second element
        return a.second < b.second;
    });

    return 0;
}

 