class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> dictionary;
        if(s.size() != t.size()) return false;
        for(char c : s){
            dictionary[c]++;
        }
        for(char c : t){
            if(dictionary.count(c)){
                if(dictionary[c] == 0) return false;
                dictionary[c]--;
            }
            else return false;
        }
        return true;
    }
};
