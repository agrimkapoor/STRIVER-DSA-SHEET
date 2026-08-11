// LFU cache

class LFUCache {
public:
    int capacity;
    int minFreq;

    unordered_map<int,int>keyToVal;
    unordered_map<int,int>keyToFreq;
    unordered_map<int,list<int>>freqToKeys;
    unordered_map<int,list<int>::iterator>keyToIter;

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        // key exist nhi karti
        if(keyToVal.find(key) == keyToVal.end())return -1;

        // key exist karti hai
        touch(key);
        return keyToVal[key];
    }
    
    void put(int key, int value) {
        // key exist karti hai
        if(keyToVal.find(key) != keyToVal.end()){
            keyToVal[key] = value;
            touch(key);
            return;
        }

        //key exist nhi karti
      
        if(keyToVal.size() == capacity){
            int KEY = freqToKeys[minFreq].back();
            freqToKeys[minFreq].pop_back();
            keyToVal.erase(KEY);
            keyToFreq.erase(KEY);
            keyToIter.erase(KEY);
        }
        
        keyToVal[key] = value;
        keyToFreq[key] = 1;
        freqToKeys[1].push_front(key);
        keyToIter[key] = freqToKeys[1].begin();
        minFreq = 1;

    }

    private : 
    void touch(int key){
        int freq = keyToFreq[key];
        auto it = keyToIter[key];
        freqToKeys[freq].erase(it);

        if(freqToKeys[freq].size()==0){
            freqToKeys.erase(freq);
            if(freq==minFreq){
                minFreq++;
            }
        }

        keyToFreq[key] = freq + 1;
        freqToKeys[freq+1].push_front(key);
        keyToIter[key] = freqToKeys[freq+1].begin(); 
    }
};
