//max xor of 2 elements in an array

#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    node*left;
    node*right;
    int no;

    node(){
        left = right = NULL;
        no=-1;
    }
};

class Trie {
public:
    node*root;
    Trie() {
        root = new node();
    }
    
    void insert(int n) {
        node*temp = root;
        for(int i=30;i>=0;i--){
            if(n&(1<<i)){
                if(temp->right){
                    temp=temp->right;
                }
                else{
                    temp->right = new node();
                    temp=temp->right;
                }
            }
            else{
                if(!temp->left){
                    temp->left = new node();
                }
                temp=temp->left;
            }
        }
        temp->no = n;
    }
    
    int f(int n){
        node*temp=root;
        for(int i=30;i>=0;i--){
            if(n&(1<<i)){
                if(temp->left){
                    temp = temp->left;
                }
                else{
                    temp=temp->right;
                }
            }
            else{
                if(temp->right){
                    temp = temp->right;
                }
                else{
                    temp = temp->left;
                }
            }
        }

        return n ^ temp->no;
    }
    
};



class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for(int i=0;i<nums.size();i++){
            t.insert(nums[i]);
        }

        int mx =0;
        for(int i=0;i<nums.size();i++){
            mx = max(mx,t.f(nums[i]));
        }
        return mx;
    }
};
