class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string anchor = strs[0];
        for(int i = 1; i < strs.size(); ++i){
            if(strs[i] == "") return "";
            for(int j = 0; j < min(anchor.size(), strs[i].size());++j){
                if(anchor[j] != strs[i][j]){
                    anchor = anchor.substr(0, j);
                    break;
                }else if(j == strs[i].size() - 1){
                    anchor = anchor.substr(0, j + 1);
                    break;
                }
            }
        }
        return anchor;
    }
};