class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxSize = 0;
        for(int i = 0; i < heights.size(); i++){
            int curMin = heights[i];
            if(i > 0 && heights[i] <= heights[i - 1]) continue;
            for(int j = i; j < heights.size(); j++){
                curMin = min(curMin, heights[j]);
                maxSize = max(maxSize, (j - i + 1) * curMin);
            }
        }
        return maxSize;
    }
};
