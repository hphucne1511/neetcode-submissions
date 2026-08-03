class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        vector<int> ans;
        for(int n : nums) count[n]++;
        for(auto& p : count){
            if(p.second > nums.size() / 3) ans.push_back(p.first);
        }
        return ans;
    }
};