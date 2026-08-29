class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        int l = 0, r = 0;
        for(r = k; r < arr.size(); r++){
            if(abs(arr[r] - x) >= abs(arr[l] - x) && arr[l] < arr[r]) break;
            l++;
        }
        for(int i = l; i < r; i++){
            res.push_back(arr[i]);
        }
        return res;
    }
};