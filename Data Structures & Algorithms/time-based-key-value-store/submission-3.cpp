class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> timap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timap[key].emplace_back(value, timestamp);
    }
    
    string get(string key, int timestamp) {
        auto& vec = timap[key];
        int l = 0, r = vec.size() - 1, res = -1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(vec[m].second <= timestamp){
                res = m;
                l = m + 1;
            }else r = m - 1;
        }
        return res != -1?vec[res].first:"";
    }
};
