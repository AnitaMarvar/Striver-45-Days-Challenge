class LRUCache {
public:
    list<int>dll;   //creates a ll with key as node->data
    int n;
    map<int, pair<list<int> :: iterator, int>>mp;  // stores: key -->[address of key in ll, value]
    LRUCache(int capacity) {
        n = capacity;
    }
    
    void mostRecentlyUsed(int key)
    {
        //get the prev address of key;
        dll.erase(mp[key].first);
        int val = mp[key].second;
        dll.push_front(key);
        mp[key] = {dll.begin(), val}; // push in front in ll 
    }
    int get(int key) {
        if(mp.find(key) == mp.end())
        {
            //key not in mp
            return -1;
        }

        //get----> most recently used therefore remove the node from present address and move at front
        mostRecentlyUsed(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {

        if(mp.find(key) != mp.end())
        {
            //already key exists
            mp[key].second = value;

            mostRecentlyUsed(key);  
        }
        else{
            //not in mp
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            n--;

        }

        if(n < 0)
        {
            //need to remove , overflow hua
            int keyToBeDeleted = dll.back();
            mp.erase(keyToBeDeleted);
            dll.pop_back();
            n++;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
