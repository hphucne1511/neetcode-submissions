class LazyPriorityQueue {
private:
    std::priority_queue<int> pq;              
    std::unordered_set<int> deleted_elements;  

public:
    void push(int val) {
        pq.push(val);
    }
    void erase(int val) {
        deleted_elements.insert(val);
    }
    void clean_top() {
        while (!pq.empty() && deleted_elements.count(pq.top())) {
            deleted_elements.erase(pq.top()); 
            pq.pop();                         
        }
    }
    int top() {
        clean_top();
        if (pq.empty()) {
            throw std::runtime_error("Queue is empty");
        }
        return pq.top();
    }
    void pop() {
        clean_top();
        if (!pq.empty()) {
            pq.pop();
        }
    }
    bool empty() {
        clean_top();
        return pq.empty();
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        LazyPriorityQueue pq;
        vector<int> ans;
        int l = 0;
        for(int r = 0; r < k; r++){
            pq.push(nums[r]);
        }
        ans.push_back(pq.top());
        for(int r = k; r < nums.size(); r++){
            pq.erase(nums[l]);
            l++;
            pq.push(nums[r]);
            ans.push_back(pq.top());
        }
        return ans;
    }
};
