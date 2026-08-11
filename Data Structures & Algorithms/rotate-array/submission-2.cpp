class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reserve(nums, 0, n - 1);
        reserve(nums, 0, k - 1);
        reserve(nums, k, n - 1);
    }
private:
    void reserve(vector<int>& vec, int l, int r){
        while(l < r){
            swap(vec[l], vec[r]);
            l++;
            r--;
        }
    }
};