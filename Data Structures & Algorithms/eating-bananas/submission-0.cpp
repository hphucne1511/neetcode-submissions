class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, res = 0;
        int r = *max_element(piles.begin(), piles.end());
        while(l <= r){
            int speed = (r + l) / 2;
            long long need = 0;
            for(int bans : piles){
                need += (bans + speed - 1) / speed;
            }
            if(need > h) l = speed + 1;
            else{
                r = speed - 1;
                res = speed;
            }
        }
        return res;
    }
};
