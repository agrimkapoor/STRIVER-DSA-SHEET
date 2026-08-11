//LRU cache

class LRUCache {
public:
    list<pair<int,int>>l;//key value
    unordered_map<int,list<pair<int,int>>::iterator>mp;
    int cap;
    LRUCache(int capacity) {
     cap = capacity;   
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())return -1;

        auto it = mp[key];//address of node
        int value = it->second;

        l.erase(it);

        l.push_front({key,value});
        mp[key] = l.begin();

        return value;

    }
    
    void put(int key, int value) {
      if(mp.find(key)==mp.end()){
            if(cap == 0){
                auto it = prev(l.end());
                int KEY = it->first;
                l.erase(it);
                mp.erase(KEY);

                l.push_front({key,value});
                mp[key]=l.begin();
            }
            else{
                l.push_front({key,value});
                mp[key]=l.begin();
                cap--;
            }
      } 
      else{
        auto it = mp[key];
        l.erase(it);

        l.push_front({key,value});
        mp[key] = l.begin();
      } 
    }
};

