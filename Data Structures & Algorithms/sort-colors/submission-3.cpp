class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3);
        for(int num : nums){
            count[num]++;
        }
        int i = 0;
        int color = 0;
        for(int c : count){
            while(c != 0){
                nums[i++] = color;
                --c;
            } 
            color++;
        }
    }
};