class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while(i < j){
            while(i < j &&nums[i] == 0) ++i;
            if(nums[j] == 0){
                swap(nums[j], nums[i]);
                ++i;
            }
            --j;
        }
        int k = nums.size() - 1;
        while(i < k){
            while(i < k && nums[i] == 1) ++i;
            if(nums[k] == 1){
                swap(nums[k], nums[i]);
                ++i;
            }
            --k;
        }
    }
};