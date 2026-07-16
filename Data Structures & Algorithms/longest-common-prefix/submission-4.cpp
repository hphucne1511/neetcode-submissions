class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        stack<char> container;
        int lsize = 200;
        string ans = "";
        for(string s : strs){
            if(s.size() < lsize){
                lsize = s.size();
            }
        }
        for(int i = 0;i < lsize;i++){
            container.push(strs[0][i]);
            for(string s : strs){
                if(container.top() != s[i]) return ans;
            }
            ans += container.top();
        }
        return ans;
    }
};