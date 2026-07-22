class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //straight selection sort
        int n = nums.size();
        for(int i = 0; i < n;++i){
            int lIdx = i;
            for(int j = i + 1; j < n; ++j){
                if(nums[lIdx] > nums[j]){
                    lIdx = j;
                }
            }
            swap(nums[lIdx], nums[i]);
        }
        return nums;
    }
};