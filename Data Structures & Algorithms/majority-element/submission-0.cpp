class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int num : nums) ++count[num];
        int max = 0;
        int major = nums[0];
        for(auto& pair : count){
            if(pair.second > max){
                max = pair.second;
                major = pair.first;
            }
        }
        return major;
    }
};