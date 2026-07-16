class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> container;
        for(int i = 0; i < nums.size(); ++i){
            if(container.contains(target - nums[i])) return {container[target - nums[i]], i};
            container.insert({nums[i], i});
        }
        return {};
    }
};
