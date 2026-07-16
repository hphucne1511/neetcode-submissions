class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(int i = 0;i < strs.size();i++){
            s += to_string(strs[i].size()) + "#" + strs[i];
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> decodedString;
        for(int i = 0;i < s.size();){
            int pos = s.find('#', i);
            int len = stoi(s.substr(i, pos - i));
            decodedString.push_back(s.substr(pos + 1, len));
            i = pos + 1 + len;
        }
        return decodedString;
    }
};