class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> container;
        for(char c : s){
            if(container.contains(c)) ++container[c];
            else container.insert({c, 1});
        }
        for(char c : t){
            if(container.contains(c) && container[c] != 0) --container[c];
            else return false;
        }
        return true;
    }
};
