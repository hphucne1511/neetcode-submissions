class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mapa;
        vector<pair<int, int>> vec;
        vector<int> ans;
        for(int num : nums){
            mapa[num]++;
        }
        for(auto& pai : mapa){
            vec.push_back({pai.second, pai.first});
        }
        sort(vec.begin(), vec.end(), greater<pair<int, int>>());
        for(int i = 0; i < k; i++){
            ans.push_back(vec[i].second);
        }
        return ans;
    }
};
