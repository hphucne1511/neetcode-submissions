class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLenght = 0, l = 0;
        unordered_set<char> wd;
        for(int r = 0; r < s.size(); r++){
            while(l < r && wd.count(s[r])){
                wd.erase(s[l]);
                l++;
            }
            wd.insert(s[r]);
            maxLenght = max(maxLenght, r - l + 1);
        }
        return maxLenght;
    }
};
