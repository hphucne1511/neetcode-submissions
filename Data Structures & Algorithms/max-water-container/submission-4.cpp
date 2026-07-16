class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0,j = n - 1;
        int max = 0;
        while(i < j){
            int size = (j - i)*min(heights[i], heights[j]);
            if(size > max) max = size;
            heights[i] > heights[j]?j--:i++;
        }
        return max;
    }
};
