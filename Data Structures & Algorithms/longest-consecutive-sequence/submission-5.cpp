class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;
        for(int num : st){
            if(!st.count(num - 1)){
                int lenght = 1;
                while(st.count(num + lenght)){
                    lenght++;
                }
                longest = max(longest, lenght);
            }  
        }
        return longest;
    }
};
