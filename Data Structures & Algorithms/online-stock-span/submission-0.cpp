class StockSpanner {
private:
    stack<int> s1, s2;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int con = 1;
        while(!s1.empty() && s1.top() <= price){
            s2.push(s1.top());
            s1.pop();
            con++;
        }
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        s1.push(price);
        return con;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */