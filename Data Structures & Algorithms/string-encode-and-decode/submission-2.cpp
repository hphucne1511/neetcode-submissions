class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedStr = "";
        for(string s : strs){
            encodedStr += to_string(s.size()) + "#" + s;
        }
        return encodedStr;
    }

    vector<string> decode(string s) {
        vector<string> decodedStr;
        for(int i = 0; i < s.size();){
            int pos = s.find('#', i);
            int size = stoi(s.substr(i, pos - i));
            decodedStr.push_back(s.substr(pos + 1, size));
            i = pos + size + 1;
        }
        return decodedStr;
    }
};
