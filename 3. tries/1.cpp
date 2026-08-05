// implementation of tries
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    char ch;
    unordered_map<char,node*> children;
    bool wordEnd;

    node(char c){
        ch = c;
        wordEnd = false;
    }
};

class Trie{
    node* root;
    public:
    Trie(){
        root = new node('\0');
    }

    void insertWord(const string&word){
        node*temp = root;
        for(char c: word){
            if(temp->children.find(c) == temp->children.end()){
                //node nhi hai toh bana do
                temp->children[c] = new node(c);
            }
            temp = temp->children[c];
        }
        temp->wordEnd = true;
    }

    bool searchWord(const string&word){
        node*temp = root;
        for(char c: word){
            if(temp->children.find(c) == temp->children.end()){
                return false;
            }
            temp = temp->children[c];
        }
        return temp->wordEnd;
    }

    //is there any word in the trie that starts with the given prefix
    bool startsWith(const string& prefix){
        node*temp = root;
        for(char c: prefix){
            if(temp->children.find(c) == temp->children.end()){
                return false;
            }
            temp = temp->children[c];
        }
        return true;
    }
};

int main(){
    Trie*trie = new Trie();
    string s = "hello";
    trie->insertWord(s);
    cout << trie->searchWord(s) << endl;
    string p = "hell";
    cout << trie->startsWith(p) << endl;

    return 0;
}
