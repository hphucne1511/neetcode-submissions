class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int, int>> st;
        int maxS = 0;
        for(int i = 0; i < heights.size(); i++){
            int popLen = i;
            while(!st.empty() && st.back().second >= heights[i]){
                int size = (i - st.back().first) * st.back().second;
                maxS = max(maxS, size);
                popLen = st.back().first;
                st.pop_back();
            }
            st.push_back({popLen, heights[i]});
        }
        while(!st.empty()){
            int size = (heights.size() - st.back().first) * st.back().second;
            maxS = max(maxS, size);
            st.pop_back();
        }
        return maxS;
    }
};
