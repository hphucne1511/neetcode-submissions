class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0,j = n - 1;
        int max = 0;
        for(int i = 0;i < n - 1;i++){
            int j = i + 1;
            while(j < n){
                int size = (j - i)*min(heights[i], heights[j]);
                if(size > max) max = size;
                j++;
            }
        }
        return max;
    }
};
