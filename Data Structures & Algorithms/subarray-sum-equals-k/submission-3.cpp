class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix;
        prefix[0] = 1;
        int count = 0, sum = 0;
        for(int num : nums){
            sum += num;
            int dif = sum - k;
            count += prefix[dif];
            prefix[sum]++;
        }
        return count;
    }
};