class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_multiset<char> container;
        for(char c : s){
            container.insert(c);
        }for(char c : t){
            if(container.count(c)) container.erase(container.find(c));
            else return false;
        }
        return true;
    }
};
