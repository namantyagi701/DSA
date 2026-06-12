class LRUCache {
public:
    int cap;
    list<pair<int,int>>dll;
    map<int , list<pair<int,int>> :: iterator> mp;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        else{
            auto node = mp[key];
            int value = node -> second;
            dll.erase(mp[key]);
            dll.push_front({key , value});
            mp[key] = dll.begin();
            return value;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            dll.erase(mp[key]);
        }
        else if(dll.size() == cap){
           auto node = dll.back();
           int lk = node.first;
           mp.erase(lk);
           dll.pop_back();
        }
        dll.push_front({key , value});
        mp[key] = dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */