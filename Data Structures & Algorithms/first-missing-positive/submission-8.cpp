class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<bool> seen(nums.size(), false);
        for(int n : nums){
            if(n < 1 || n > nums.size()) continue;
            seen[n - 1] = true;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(!seen[i]) return i + 1;
        }
        return nums.size() + 1;
    }
};