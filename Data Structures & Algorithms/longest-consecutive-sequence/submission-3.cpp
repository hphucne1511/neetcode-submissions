class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int i = 0, longest = 0;
        while(i < nums.size()){
            int lenght = 0;
            int curr = nums[i];
            if(!st.count(curr - 1)){
                while(st.count(curr)){
                    curr++;
                    lenght++;
                }
            }
            i++;
            longest = max(longest, lenght);
        }
        return longest;
    }
};
