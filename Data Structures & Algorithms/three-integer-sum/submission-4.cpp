class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_map<int, int> count;
        vector<vector<int>> ans;
        for(int i = 0; i < n;i++){
            count[nums[i]]++;
        }
        for(int i = 0; i < n; i++){
            count[nums[i]]--;
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < n; j++){
                count[nums[j]]--;
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                int target = 0 - (nums[i] + nums[j]);
                if(count[target] > 0){
                    ans.push_back({nums[i], nums[j], target});
                }
            }
            for(int j = i + 1; j < n; j++) count[nums[j]]++;
        }
        return ans;
    }
};
