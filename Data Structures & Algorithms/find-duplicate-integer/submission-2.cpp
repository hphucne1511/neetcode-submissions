class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool> flag(10000);
        for(int num : nums){
            if(flag[num]) return num;
            flag[num] = true;
        }
        return 0;
    }
};
