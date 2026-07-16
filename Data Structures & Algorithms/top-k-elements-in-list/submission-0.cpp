class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int i : nums){
            count[i]++;
        }
        vector<pair<int, int>> sortedCount;
        for(auto p : count){
            sortedCount.push_back({p.second, p.first});
        }
        sort(sortedCount.begin(), sortedCount.end(), greater<pair<int, int>>());
        int n = 0;
        vector<int> res;
        for(auto p : sortedCount){
            if(n == k) break;
            res.push_back(p.second);
            n++;
        }
        return res;
    }
};
