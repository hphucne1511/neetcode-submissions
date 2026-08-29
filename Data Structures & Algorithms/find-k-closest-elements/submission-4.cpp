class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = 0;
        for(r = k; r < arr.size(); r++){
            if(abs(arr[r] - x) >= abs(arr[l] - x) && arr[l] < arr[r]) break;
            l++;
        }
        return vector<int>(arr.begin() + l, arr.begin() + r);
    }
};