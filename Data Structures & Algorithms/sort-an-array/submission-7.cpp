class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //straight selection sort
        for(int i = 0; i < nums.size();++i){
            int min = nums[i];
            int j = i;
            int lIdx = j;
            while(j < nums.size()){
                if(min > nums[j]){
                    min = nums[j];
                    lIdx = j;
                }
                j++;
            }
            int temp = nums[i];
            nums[i] = nums[lIdx];
            nums[lIdx] = temp;
        }
        return nums;
    }
};