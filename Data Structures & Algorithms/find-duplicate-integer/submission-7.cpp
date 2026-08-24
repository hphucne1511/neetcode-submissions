class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        long long bit[157] = {0};
        for(long long n : nums){
            if(bit[n / 64] & (1ULL << (n % 64))) return n;
            bit[n / 64] |= (1ULL << (n % 64));
        }
        return 0;
    }
};
