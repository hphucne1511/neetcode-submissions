class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        stack<char> container;
        string ans = "";
        for(int i = 0;i < strs[0].size();i++){
            container.push(strs[0][i]);
            for(string s : strs){
                if(i >= s.size() || container.top() != s[i]) return ans;
            }
            ans += container.top();
        }
        return ans;
    }
};