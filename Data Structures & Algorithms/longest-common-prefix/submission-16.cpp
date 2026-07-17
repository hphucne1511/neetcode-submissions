class node {
public:
    unordered_map<char, node*> next;
};

class trie {
private:
    node* root;
public:
    trie(){
        root = new node();
    }
    void insert(const string& s){
        node* n = root;
        for(char c : s){
            if(n->next.find(c) == n->next.end()){
                n->next[c] = new node();
            }
            n = n->next[c];
        }
    }
    int lcp(const string& s, int prefixLen){
        node* n = root;
        int i = 0;
        while(i < min((int)s.size(), prefixLen)){
            if(n->next.find(s[i]) == n->next.end())
                return i;
            n = n->next[s[i]];
            ++i;
        }
        return min((int)s.size(), prefixLen);
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }
        int mini = 0;
        for(int i = 0; i < strs.size(); i++){
            if(strs[mini].size() > strs[i].size()) mini = i;
        }
        trie t;
        t.insert(strs[mini]);
        int prefixLen = strs[mini].size();
        for(int i = 0; i < strs.size();++i){
            prefixLen = t.lcp(strs[i], prefixLen);
        }
        return strs[0].substr(0, prefixLen);
    }
};