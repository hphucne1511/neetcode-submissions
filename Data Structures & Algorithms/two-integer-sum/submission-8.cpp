class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int ,int> dict;
        for(int i = 0;i < nums.size();i++){
            dict.insert({nums[i], i});
        }
        for(int i = 0;i < nums.size();i++){
            if(dict.count(target - nums[i]) && dict[target - nums[i]] != i){
                return {min(i, dict[target - nums[i]]), max(i, dict[target - nums[i]])};
            }
        }
        return {};
    }
};
