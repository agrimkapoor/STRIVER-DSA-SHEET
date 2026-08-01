// common bit manipulation tricks 

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n = 5; // binary representation of 5 is 101

    //1.Check if the ith bit is set or not (0-based indexing and from right to left)
    int i = 2;
    if(n & (1 << i)){
        // the ith bit is set
        cout << 1;
    }
    else cout << 0;
    //concept : bit & 0 = 0 and bit & 1 = bit (checks if the bit is set or not)

    //2. set the ith bit
    n = n | (1<<i);
    //concept : bit | 0 = bit and bit | 1 = 1(sets the bit)

    //3. clear the ith bit
    n = n & (~(1<<i));
    //concept : bit & 0 = 0 and bit & 1 = bit (clears the bit)

    //4. toggle the ith bit
    n = n ^ (1<<i);
    // concept : bit ^0 = bit and bit ^1 = ~bit (flips the bit)


    //5.print all the bits of a number
    for(int i = 31; i>=0; i--){
        cout << (n &(1<<i))?1:0;// if the ith bit is set print 1 else print 0
    }//32 bits but the last bit is the sign bit we can ignore it 

    //6. count the number of set bits
    int count = __builtin_popcount(n); // counts the number of set bits in an integer
    int count2 = __builtin_popcountll(n);// counts the number of set bits in a long long 

    int cnt = 0;
    for(int i = 0; i<32; i++){
        if(n & (1<<i)) cnt++;
    }

    //7.check if a number is a power of 2 or not
    if(n>0 && (n & (n-1))==0){
        cout << "Yes";
    }
    else cout << "No";

    //8. get the rightmost set bit
    int rightmost_set_bit = n & (-n);
    //concept : -n is the 2's complement of n which is equal to ~n + 1. So, n & -n gives the rightmost set bit.

    //9.remove the rightmost set bit
    n = n & (n-1);

    //10.bitmasking is a technique to represent a set of elements using bits. Each bit represents whether an element is present or not. For example, if we have a set of 5 elements, we can represent it using a 5-bit number where each bit represents whether the corresponding element is present (1) or not (0).

    //11. check if a number is even or odd
    if(n & 1) cout << "Odd";
    else cout << "Even";

    //12. swap two numbers using XOR
    int a = 5, b = 10;
    a = a ^ b;  
    b = a ^ b;
    a = a ^ b;

    //13. minimum bit flips to convert a to b
    int a1 = 5, b1 = 10;
    int flips = __builtin_popcount(a1 ^ b1); // XOR of a and

    return 0;
}