class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> ans;
        for(int num : nums){
            if(num != val) ans.push_back(num);
        }
        nums = ans;
        return ans.size();
    }
};