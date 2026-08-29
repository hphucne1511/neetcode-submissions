class Solution {
public:
    string minWindow(string s, string t) {
        pair<int, int> minL = {0, s.size() + 1};
        unordered_map<int, int> count1, count2;
        if(t.size() > s.size()) return "";
        for(char c : t) count1[c]++;
        for(int i = 0; i < t.size(); i++){
            if(count1.count(s[i])) count2[s[i]]++;
        }
        if(count1 == count2) return s.substr(0, t.size());
        int l = 0;
        for(int r = t.size(); r < s.size(); r++){
            if(count1.count(s[r]))
                count2[s[r]]++;
            while(!count1.count(s[l]) || count1[s[l]] < count2[s[l]]){
                if(count1.count(s[l]))
                    count2[s[l]]--;
                l++;
            }
            bool valid = true;
            for(auto& p : count1){
                if(!count2.count(p.first) || count2[p.first] < p.second) valid = false;
            }
            if(valid && r - l + 1 < minL.second) minL = {l, r - l + 1};
        }
        return (minL.second == s.size() + 1)?"":s.substr(minL.first, minL.second);

    }
};
