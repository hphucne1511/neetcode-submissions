class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, sum = 0, ml = nums.size() + 1;
        for(int r = 0; r < nums.size(); r++){
            sum += nums[r];
            while(sum - nums[l] >= target){
                sum -= nums[l];
                l++;
            }
            if(sum >= target)
                ml = min(ml, r - l + 1);
        }
        return (ml != nums.size() + 1)?ml:0;
    }
};