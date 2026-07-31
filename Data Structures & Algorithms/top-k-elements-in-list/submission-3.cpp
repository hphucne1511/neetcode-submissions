class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<queue<int>> feq(nums.size() + 1);
        vector<int> ans;
        unordered_map<int, int> table;
        for(int num : nums) table[num]++;
        for(auto& pa : table) feq[pa.second].push(pa.first);
        int i = nums.size();
        while(k > 0){
            if(!feq[i].empty()){
                ans.push_back(feq[i].front());
                feq[i].pop();
                k--;
                i++;
            }
            i--;
        }
        return ans;
    }
};
