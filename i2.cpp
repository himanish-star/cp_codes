#include<bits/stdc++.h>

using namespace std;

class solution {
    private:
        int csize;
        list<int> dq; // snapshot of the cache
        unordered_map<int,list<int>::iterator> mp;
        unordered_map<int,int> keyVal;

    public:
        void init(int capacity) {
            csize=capacity;
        }
        
        void del(int key) {
            if(keyVal.find(key)==keyVal.end()) {
                // not present in the cache
                //do nothing
            } else {
                keyVal.erase(key);
                mp.erase(key);
            }
        }

        void put(int key, int val) {
            if(keyVal.find(key)==keyVal.end()) {
                // not present already
                if(dq.size()==csize) {
                    // handle case for cache size at max capacity ******
                    // remove least recently used
                    dq.pop_back();
                    mp.erase(key);
                    keyVal.erase(key);
                } 
                dq.push_front(key);
                mp[key]=dq.begin();
                keyVal.insert({key,val});
            } else {
                // present already
                dq.erase(mp[key]);
                keyVal[key]=val;
                dq.push_front(key);
                mp[key]=dq.begin();
            }
        }

        int get(int key) {
            if(mp.find(key)==mp.end()) {
                return -1;
            } else {
                // present in the LRU cache itself
                dq.erase(mp[key]);
                dq.push_front(key);
                mp[key]=dq.begin();
                return keyVal[key];
            }
        }
}