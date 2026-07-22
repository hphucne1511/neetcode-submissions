class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // straight insertion sort
        for(int i = 1; i < nums.size();++i){
            for(int j = 0; j < i; ++j){
                if(nums[i] < nums[j]){
                    nums.insert(nums.begin() + j, nums[i]);
                    nums.erase(nums.begin() + i + 1);
                }
            }
        }
        return nums;
    }
};