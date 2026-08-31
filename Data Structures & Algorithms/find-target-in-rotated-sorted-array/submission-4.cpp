class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int m = l + (r - l)/2;
            if(nums[m] > nums[r]) l = m + 1;
            else r = m;
        }
        if(target >= nums[l] && target <= nums[nums.size() - 1]){
            return binSearch(nums, target, l, nums.size() - 1);
        }
        return binSearch(nums, target, 0, l - 1);
    }
    int binSearch(vector<int>& nums, int target, int l, int r){
        while(l <= r){
            int m = l + (r - l)/2;
            if(nums[l] == target) return l;
            if(nums[m] == target) return m;
            else if(nums[m] > target) r = m - 1;
            else l = m + 1;
        }
        return -1;
    }
};
