class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> dict;
        for(string s : strs){
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            dict[sortedS].push_back(s);
        }
        for(auto& an : dict){
            ans.push_back(an.second);
        }
        return ans;
    }
};