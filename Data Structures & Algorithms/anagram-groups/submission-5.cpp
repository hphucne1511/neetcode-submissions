class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<char, int> primeMap = {
            {'a', 2},  {'b', 3},  {'c', 5},  {'d', 7},
            {'e', 11}, {'f', 13}, {'g', 17}, {'h', 19},
            {'i', 23}, {'j', 29}, {'k', 31}, {'l', 37},
            {'m', 41}, {'n', 43}, {'o', 47}, {'p', 53},
            {'q', 59}, {'r', 61}, {'s', 67}, {'t', 71},
            {'u', 73}, {'v', 79}, {'w', 83}, {'x', 89},
            {'y', 97}, {'z', 101}
        };
        unordered_map<int, vector<string>> container;
        for(string s : strs){
            int key = 1;
            for(char c : s){
                key *= primeMap[c];
            }
            container[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto& an : container){
            ans.push_back(an.second);
        }
        return ans;
    }
};
