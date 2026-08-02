class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int count = 1;
        int maxCount = 1;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i + 1] == nums[i]) continue;
            if(nums[i + 1] == nums[i] + 1){
                count += 1;
                if(count > maxCount) maxCount = count;
            }else{
                count = 1;
            }
        }
        return maxCount;
    }
};
