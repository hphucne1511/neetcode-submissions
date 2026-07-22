class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //straight selection sort
        for(int i = 0; i < nums.size();++i){
            int lIdx = i;
            for(int j = i + 1; j < nums.size(); ++j){
                if(nums[lIdx] > nums[j]){
                    lIdx = j;
                }
            }
            swap(nums[lIdx], nums[i]);
        }
        return nums;
    }
};