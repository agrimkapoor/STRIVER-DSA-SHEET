//word ladder 1


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(),wordList.end());
        if(s.find(beginWord) == s.end()){
            s.insert(beginWord);
        }

        queue<pair<string,int>>q;//{word,length}
        q.push({beginWord,1});
        auto it = s.find(beginWord);
        s.erase(it);// removing from set is like marking it visited

        while(!q.empty()){
            auto f = q.front();
            q.pop();
            string word = f.first;
            int len = f.second;

            if(word==endWord)return len;//jaise hi pehli baar pahuche ho toh woh hi shortest route hai

            for(int i=0;i<word.size();i++){
                char ch = word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c; 
                    if(s.find(word)!=s.end()){
                        q.push({word,len+1});
                        auto it = s.find(word);
                        s.erase(it);
                    }
                }
                word[i]=ch;
            }
        }
        return 0;
    }
};