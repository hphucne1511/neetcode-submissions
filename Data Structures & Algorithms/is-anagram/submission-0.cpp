class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n != m) return false;
        vector<char> chest;
        for(char c : s){
            chest.push_back(c);
        }
        for(char c : t){
            if(find(chest.begin(), chest.end(), c) != chest.end()){
                chest.erase(find(chest.begin(), chest.end(), c));
            }
            else return false;
        }
        if(chest.empty()) return true;
        else return false;
    }
};
