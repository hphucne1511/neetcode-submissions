class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, res = 0;
        while(l <= r){
            long long m = l + (r - l) / 2;
            if(m * m == (long long)x) return m;
            else if(m * m < (long long)x){
                res = m;
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
        return res;
    }
};