class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int, int> count1, count2;
        pair<int, int> res = {0, INT_MAX};
        for(char c : t) count1[c]++;
        int l = 0, have = 0, need = count1.size();
        for(int r = 0; r < s.size(); r++){
            char c = s[r];
            count2[c]++;
            if(count1.count(c) && count2[c] == count1[c]) have++;
            while(need == have){
                if(r - l + 1 < res.second) res = {l, r - l + 1};
                count2[s[l]]--;
                if(count1.count(s[l]) && count2[s[l]] < count1[s[l]]){
                    have--;
                }
                l++;
            }
        }
        return res.second == INT_MAX?"":s.substr(res.first, res.second);
    }
};
