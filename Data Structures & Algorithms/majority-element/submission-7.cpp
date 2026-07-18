class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        int n = nums.size()/2;
        for(int num : nums){
            ++count[num];
            if(count[num] > n) return num;
        }
        return nums[0];
    }
};