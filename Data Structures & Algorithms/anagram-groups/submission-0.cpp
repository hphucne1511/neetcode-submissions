class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<pair<string, int>> dict;
        for(int i = 0;i < strs.size();i++){
            dict.push_back({strs[i], i});
            sort(dict[i].first.begin(), dict[i].first.end());
        }
        sort(dict.begin(), dict.end());
        for(int i = 0;i < strs.size();){
            vector<string> group;
            group.push_back(strs[dict[i].second]);
            int j = 1;
            for(;i + j < strs.size();j++){
                if(dict[i].first == dict[i + j].first){
                    group.push_back(strs[dict[i + j].second]);
                }
                else{
                    break;
                }
            }
            ans.push_back(group);
            i += j;
        }
        return ans;
    }
};