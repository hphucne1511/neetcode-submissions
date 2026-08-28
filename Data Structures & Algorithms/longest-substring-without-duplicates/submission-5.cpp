class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLenght = 0, l = 0;
        unordered_map<char, int> wd;
        for(int r = 0; r < s.size(); r++){
            if(wd.count(s[r]) && wd[s[r]] >= l){
                l = wd[s[r]] + 1;
            }
            wd[s[r]] = r;
            maxLenght = max(maxLenght, r - l + 1);
        }
        return maxLenght;
    }
};
