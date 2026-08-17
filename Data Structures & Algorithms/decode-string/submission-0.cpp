class Solution {
public:
    string decodeString(string s) {
        vector<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ']'){
                string en, num;
                int k = 0;
                while(!st.empty()){
                    if(st.back() == '['){
                        st.pop_back();
                        reverse(en);
                        while(!st.empty() && st.back() >= '0' && st.back() <= '9'){
                            num += st.back();
                            st.pop_back();
                        }
                        reverse(num);
                        k = stoi(num);
                        for(int t = 0; t < k; t++){
                            for(char p : en) st.push_back(p);
                        }
                        break;
                    }else{
                        en += st.back();
                        st.pop_back();
                    }
                }
            }else{
                st.push_back(s[i]);
            }
        }
        string res;
        for(int i = 0; i < st.size(); i++){
            res += st[i];
        }
        return res;
    }
    void reverse(string& s){
            int i = 0, j = s.size() - 1;
            while(i < j){
                swap(s[i], s[j]);
                i++;
                j--;
            } 
        }
};