class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> cop(nums);
        cop.reserve(2*n);
        for(size_t i = 0; i < n; ++i){
            cop.push_back(nums[i]);
        }
        return cop;
    }
};