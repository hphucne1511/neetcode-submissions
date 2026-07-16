class Solution {
public:
    bool isPalindrome(string s) {
        string res = "";
        for(char c : s){
            if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
                res += tolower(c);
            }
        }
        int i = 0,j = res.size() - 1;
        while(i < j){
            if(res[i] != res[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
