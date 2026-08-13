class MyStack {
public:
    queue<int> que;
    MyStack() {
        
    }
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        queue<int> temp;
        while(que.size() != 1){
            temp.push(que.front());
            que.pop();
        }
        int t = que.front();
        que = temp;
        return t;
    }
    
    int top() {
        queue<int> temp;
        while(que.size() != 1){
            temp.push(que.front());
            que.pop();
        }
        int t = que.front();
        que = temp;
        que.push(t);
        return t;
    }
    
    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */