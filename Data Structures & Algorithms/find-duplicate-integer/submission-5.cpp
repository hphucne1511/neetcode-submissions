class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        uint64_t bit[157] = {0};
        for(size_t n : nums){
            if(bit[n / 64] & (1ULL << (n % 64))) return n;
            bit[n / 64] |= (1ULL << (n % 64));
        }
        return 0;
    }
};
