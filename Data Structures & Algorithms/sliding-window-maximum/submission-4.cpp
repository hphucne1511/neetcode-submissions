
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        if(k == 1) return nums;
        vector<int> ans;
        int l = 0;
        for(int r = 0; r < k; r++){
            pq.push({nums[r], r});
        }
        ans.push_back(pq.top().first);
        for(int r = k; r < nums.size(); r++){
            while(pq.top().second <= l) pq.pop();
            l++;
            pq.push({nums[r], r});
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};
