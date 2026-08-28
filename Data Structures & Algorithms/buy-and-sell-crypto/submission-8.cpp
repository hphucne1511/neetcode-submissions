class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pro = 0;
        int l = 0;
        for(int r = 0; r < prices.size(); r++){
            if(prices[r] < prices[l]) l = r;
            pro = max(pro, prices[r] - prices[l]);
        }
        return pro;
    }
};
