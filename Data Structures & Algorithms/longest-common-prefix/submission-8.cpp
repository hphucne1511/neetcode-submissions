class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int count = 0;
        for(char c : strs[0]){
            for(const string& s : strs){
                if(count >= s.size() || s[count] != c) return s.substr(0, count);
            }
            count++;
        }
        return strs[0];
    }
};