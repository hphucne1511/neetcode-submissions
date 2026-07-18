class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        int maxCount = 0;
        int major = nums[0];
        for(int num : nums){
            ++count[num];
            if(count[num] > maxCount){
                maxCount = count[num];
                major = num;
            }
        } 
        return major;
    }
};