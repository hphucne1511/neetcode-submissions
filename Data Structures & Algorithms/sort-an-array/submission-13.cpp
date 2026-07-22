class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //Shell sort
        int k = 1;
        int n = nums.size();
        while(k < n) k = 3*k + 1;
        while(k >= 1){
            k = (k - 1)/3;
            int segment = 0;
            while(segment < k){
                for(int i = segment + k; i < n; i += k){
                    int key = nums[i];
                    int j = i - k;
                    while(j >= 0 && nums[j] > key){
                        nums[j + k] = nums[j];
                        j -= k;
                    }
                    nums[j + k] = key;
                }
                segment++;
            }
        }
        return nums;
    }
};