class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        int l = 0;
        for(int r = 0; r < k; r++){
            res.push_back(arr[r]);
        }
        for(int r = k; r < arr.size(); r++){
            if(abs(arr[r] - x) >= abs(arr[l] - x) && arr[l] < arr[r]) return res;
            res.push_back(arr[r]);
            res.erase(res.begin());
            l++;
        }
        return res;
    }
};