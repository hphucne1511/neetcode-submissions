class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0;
        int i = 0, j = n - 1;
        int res = 0;
        int maxL = 0;
        int maxR = 0;
        while(i < j){
            if(height[i] < height[j]){
                if(maxL <= height[i]){
                    maxL = height[i];
                }
                else{
                    res += maxL - height[i];
                }
                i++;
            }
            else{
                if(maxR <= height[j]){
                    maxR = height[j];
                }
                else{
                    res += maxR - height[j];
                }
                j--;
            }
        }
        return res;
    }
};
