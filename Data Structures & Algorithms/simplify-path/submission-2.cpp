class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        for(int i = 0; i < path.size(); i++){
            if(path[i] == '/') path[i] = ' ';
        }
        stringstream ss(path);
        string word;
        while(ss >> word){
            if(word == "..") {
                if(!st.empty()) st.pop_back();
            }else if(word != ".") st.push_back(word);
        }
        string res = "/";
        for(int i = 0; i < st.size(); i++){
            if(i > 0) res += "/";
            res += st[i];
        }
        return res;
    }
};