class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int res = 0, l = *max_element(weights.begin(), weights.end()), r = l * weights.size();
        while(l <= r){
            int cap = 1;
            int m = (r + l)/2, cur = 0;
            for(int weight : weights){
                if(cur + weight > m){
                    cap++;
                    cur = weight;
                }else cur += weight;
            }
            if(cap > days) l = m + 1;
            else{
                res = m;
                r = m - 1;
            }
        }
        return res;
    }
};