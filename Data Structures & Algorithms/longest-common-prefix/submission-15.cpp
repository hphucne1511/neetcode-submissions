class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string anchor = strs[0];
        for(int i = 1; i < strs.size(); ++i){
            int j = 0;
            while(j < min(anchor.size(), strs[i].size())){
                if(anchor[j] != strs[i][j]) break;
                j++;
            }
            anchor = anchor.substr(0, j);
        }
        return anchor;
    }
};