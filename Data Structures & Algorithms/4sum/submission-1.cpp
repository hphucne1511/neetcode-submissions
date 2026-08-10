class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i = 0; i < n - 3; i++){  
            if(i > 0 && nums[i] == nums[i - 1]) continue;  
            for(int s = i + 1; s < n - 2; s++){
                if(s > i + 1 && nums[s] == nums[s - 1]) continue;  
                int j = s + 1, k = n - 1;
                while(j < k){
                    long long sum =(long long) nums[j] + nums[k] + nums[i] + nums[s];
                    if(sum < target) j++;
                    else if(sum > target) k--;
                    else{
                        res.push_back({nums[i], nums[s], nums[j], nums[k]});
                        j++;
                        k--;
                        while(j < k && nums[j] == nums[j - 1]) j++;
                        while(j < k && nums[k] == nums[k + 1]) k--;
                    }
                }
            } 
        }
        return res;
    }
};