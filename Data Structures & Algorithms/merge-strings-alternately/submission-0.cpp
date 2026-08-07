class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int s1 = word1.size(), s2 = word2.size();
        int s = min(s1, s2);
        for(int i = 0; i < s; i++){
            ans += word1[i];
            ans += word2[i];
        }
        if(s == s1 && s == s2) return ans;
        else if(s == s1) ans += word2.substr(s, s2 - s + 1);
        else ans += word1.substr(s, s1 - s + 1);
        return ans;
    }
};