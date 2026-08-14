class MinStack {
private:
    long curMin;
    stack<long> s;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            curMin = val;
        }   
        s.push(val - curMin);
        curMin = min(curMin, (long)val);
    }
    
    void pop() {
        if(s.top() < 0){
            curMin -= s.top();
        }
        s.pop();
    }
    
    int top() {
        return (s.top() > 0) ? (s.top() + curMin) : curMin;
    }
    
    int getMin() {
        return curMin;
    }
};
