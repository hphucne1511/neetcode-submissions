class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> res(nums.begin(), nums.end());
        if(nums.empty()) return 0;
        int longest = 1;
        for(int n : res){
            int lenght = 1;
            if(!res.count(n - 1)){
                while(res.count(n + lenght)){
                    lenght++;
                }
                longest = longest < lenght?lenght:longest;
            }
        }
        return longest;
    }
};
