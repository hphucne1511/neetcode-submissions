class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int products = 1;
        int nonzero = 1;
        vector<int> output;
        bool isZero = false;
        for(int num : nums){    
            products *= num;
            if(!isZero && num == 0){
                isZero = true;
                continue;
            }
            nonzero *= num;
        } 
        for(int num : nums){
            if(num == 0){
                output.push_back(nonzero);
                continue;
            }
            output.push_back(products / num);
        }
        return output;
    }
};
