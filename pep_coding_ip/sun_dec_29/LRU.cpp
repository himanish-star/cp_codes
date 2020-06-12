class LRUCache {
    list<int> dq;
    unordered_map<int,list<int>::iterator> mp;
    unordered_map<int,int> keyVal;
    int csize;
public:
    LRUCache(int capacity) {
        csize=capacity;
    }
    
    int get(int key) {
        if(keyVal.find(key)!=keyVal.end()) {
            dq.erase(mp[key]);
            dq.push_front(key);
            mp[key]=dq.begin();
            return keyVal[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end()) {
            if(dq.size()==csize) {
                int remKey=dq.back(); dq.pop_back();
                mp.erase(remKey);
                keyVal.erase(remKey);
            }
        } else {
            dq.erase(mp[key]);
        }
        
        dq.push_front(key);
        mp[key]=dq.begin();
        keyVal[key]=value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */