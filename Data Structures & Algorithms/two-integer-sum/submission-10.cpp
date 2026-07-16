class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int ,int> dict;
        for(int i = 0;i < nums.size();i++){
            int complement = target - nums[i];

            if(dict.find(complement) != dict.end()){
                return {dict[complement], i};
            }
            dict.insert({nums[i], i});

        }
        
        return {};
    }
};
