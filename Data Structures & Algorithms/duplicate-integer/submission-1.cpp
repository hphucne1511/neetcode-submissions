class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(unsigned i = 0;i < nums.size();i++){
            if(i + 1 < nums.size() && nums[i + 1] == nums[i]) return true;
        }
        return false;
    }
};