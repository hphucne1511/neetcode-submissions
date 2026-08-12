class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1, maxl = 0, maxr = 0, res = 0;
        while(l < r){
            if(height[l] <= height[r]){
                if(maxl < height[l]){
                    maxl = height[l++];
                }else{
                    res += maxl - height[l++];
                }
            }else{
                if(maxr < height[r]){
                    maxr = height[r--];
                }else{
                    res += maxr - height[r--];
                }
            }
        }
        return res;
    }
};
