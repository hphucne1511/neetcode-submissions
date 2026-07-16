class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        nums.resize(n * 2); 
        copy_n(nums.begin(), n, nums.begin() + n); 
        return nums;
    }
};