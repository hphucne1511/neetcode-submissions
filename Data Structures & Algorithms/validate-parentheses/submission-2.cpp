class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(char c : s){
            switch (c) {
                case '{': st.push(1); break;
                case '[': st.push(2); break;
                case '(': st.push(3); break;
                case '}':
                    if(!st.empty() && st.top() == 1) st.pop();
                    else return false;
                    break;
                case ']':
                    if(!st.empty() && st.top() == 2) st.pop();
                    else return false;
                    break;
                case ')':
                    if(!st.empty() && st.top() == 3) st.pop();
                    else return false;
                    break;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};
