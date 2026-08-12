class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n), rightMax(n);
        int res = 0, maxL = 0, maxR = 0;
        for(int i = 0; i < n; i++){
            maxL = max(maxL, height[i]);
            maxR = max(maxR, height[n - i - 1]);
            leftMax[i] = maxL;
            rightMax[n - i - 1] = maxR;
        }
        for(int i = 0; i < n; i++){
            res += min(leftMax[i], rightMax[i]) - height[i];
        }
        return res;
    }
};
