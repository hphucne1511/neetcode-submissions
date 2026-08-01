class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) return "";
        vector<int> sizes;
        string s = "";
        for(string a : strs){
            sizes.push_back(a.size());
        }
        for(int i = 0; i < sizes.size(); i++){
            s += to_string(sizes[i]) +  ",";
        }
        s += "#";
        for(string a : strs) s += a;
        return s; 
    }

    vector<string> decode(string s) {
        if (s.empty()) return {};
        vector<int> sizes;
        vector<string> ans;
        int i = 0;
        while(s[i] != '#'){
            int pos = s.find(',', i);
            sizes.push_back(stoi(s.substr(i, pos - i)));
            i = pos + 1;
        }
        i++;
        for(int j = 0; j < sizes.size(); j++){
            ans.push_back(s.substr(i, sizes[j]));
            i += sizes[j];
        }
        return ans;
    }   
};
