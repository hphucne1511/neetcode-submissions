class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        char a[26] = {0};
        for(int i = 0; i < s.size(); ++i){
            a[s[i] - 'a']++;
            a[t[i] - 'a']--;
        }
        for(int i : a){
            if(i != 0) return false;
        }
        return true;
    }
};
