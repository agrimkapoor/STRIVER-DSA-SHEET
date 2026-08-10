// LRU cache

class LRUCache {
public:
    list<pair<int,int>>l;//key value pair
    unordered_map<int,list<pair<int,int>>::iterator>mp;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;

        auto it = mp[key];
        int value = it->second;
       
        l.erase(it);
        l.push_front({key,value});
        mp[key] = l.begin();
        return value;
    }
    
    void put(int key, int value) {

        if(mp.find(key)!=mp.end()){
            auto it = mp[key];
            l.erase(it);
            
            
            l.push_front({key,value});
            mp[key] = l.begin();
        }
        else{
            if(cap==0){
                auto it = prev(l.end());
                mp.erase(it->first);
                l.erase(it);
            }
            else{
                cap--;
            }
            l.push_front({key,value});
            mp[key] = l.begin();
        }
        
    }
};

