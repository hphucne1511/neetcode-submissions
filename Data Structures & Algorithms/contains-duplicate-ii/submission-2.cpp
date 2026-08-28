class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {;
        unordered_set<int> us;
        if(!k) return false;
        for(int i = 0; i < k; i++){
            if(us.count(nums[i])) return true;
            us.insert(nums[i]);
        }
        for(int j = k; j < nums.size(); j++){
            if(us.count(nums[j])) return true;
            us.erase(nums[j - k]);
            us.insert(nums[j]);
        }
        return false;
    }
};