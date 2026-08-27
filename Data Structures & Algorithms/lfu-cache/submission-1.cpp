class LFUCache {
private:
    unordered_map<int, pair<int, pair<int, list<int>::iterator>>> cache;
    unordered_map<int, list<int>> count;
    int cap;

public:
    LFUCache(int capacity) : cap(capacity) {
        
    }
    
    int get(int key) {
        if(!cache.count(key)) return -1;
        int cnt = cache[key].second.first;
        count[cnt].erase(cache[key].second.second);
        count[++cnt].push_back(key);
        cache[key].second = {cnt, --count[cnt].end()};
        return cache[key].first;
    }
    
    void put(int key, int value) {
        int cnt = 0;
        if(cache.count(key)){
            cnt = cache[key].second.first;
            count[cnt].erase(cache[key].second.second);
        }else if(cache.size() == cap){
            int minCnt = 0;
            while(count[++minCnt].empty());
            cache.erase(count[minCnt].front());
            count[minCnt].pop_front();
        }
        count[++cnt].push_back(key);
        cache[key] = {value, {cnt, --count[cnt].end()}};

    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */