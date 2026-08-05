//leetcode 1707
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        vector<int>ans(queries.size());
        vector<pair<pair<int,int>,int>>arr;//{{xi,mi},query_no}

        for(int i=0;i<queries.size();i++){
            int u = queries[i][0];
            int v = queries[i][1];
            arr.push_back({{u,v},i});
        }
        sort(arr.begin(),arr.end(),[](const auto &a,const auto&b){
            return a.first.second < b.first.second;
        });

        Trie t;

        int k=0;
        int n = nums.size();
        
        for(int i=0;i<arr.size();i++){

            int x = arr[i].first.first;
            int m = arr[i].first.second;
            int indx = arr[i].second;

            while(k<n and nums[k]<=m){
                t.insert(nums[k]);
                k++;
            }
            if(k == 0){
                ans[indx] = -1;
            }
            else{
                ans[indx] = t.f(x);
            }
            

        }
        return ans;


    }
};
