class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        for(int n : nums){
            dict[n]++;
        }
        vector<pair<int, int>> pa;
        for(const auto& p : dict){
            pa.push_back({p.second, p.first});
        }
        sort(pa.begin(), pa.end(), greater<pair<int, int>>());
        vector<int> ans;
        for(int i = 0;i < k;i++){
            ans.push_back(pa[i].second);
        }
        return ans;
    }
};
