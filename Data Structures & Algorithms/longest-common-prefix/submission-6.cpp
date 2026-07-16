class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int count = 0;
        string ans = "";
        for(char c : strs[0]){
            for(string s : strs){
                if(count >= s.size() || s[count] != c) return ans;
            }
            ans += c;
            ++count;
        }
        return ans;
    }
};