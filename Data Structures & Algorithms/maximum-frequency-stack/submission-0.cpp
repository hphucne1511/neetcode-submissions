class FreqStack {
public:
    unordered_map<int, int> count;
    vector<stack<int>> st;
    FreqStack() {
        st.push_back(stack<int>());
    }
    
    void push(int val) {
        int countVal = ++count[val];
        if(countVal >= st.size()) st.push_back(stack<int>());
        st[countVal].push(val);
    }
    
    int pop() {
        stack<int> cur = st.back();
        int elem = cur.top();
        --count[elem];
        st.back().pop();
        if(st.back().empty()) st.pop_back();
        return elem;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */