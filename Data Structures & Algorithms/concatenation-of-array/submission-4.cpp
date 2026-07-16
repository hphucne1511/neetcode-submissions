class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        ans.reserve(nums.size() * 2);
        for (int i = 0; i < 2; ++i) {
            for (int num : nums) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};