class Solution {
public:
    void mergeSort(vector<int>& arr, int left, int right, vector<int>& temp){
        int mid = left + ((right - left) >> 1);
        if (left >= right) return;
        mergeSort(arr, left, mid, temp);
        mergeSort(arr, mid + 1, right, temp);
        merge(arr, left, mid, right, temp);

    }
    void merge(vector<int>& arr, int left, int mid, int right, vector<int>& temp){
        int i = left, j = mid + 1;
        int k = left;
        while(i <= mid && j <= right){
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            }else{
                temp[k++] = arr[j++];
            }
        }
        while(i <= mid){
            temp[k++] = arr[i++];
        }
        while(j <= right){
            temp[k++] = arr[j++];
        }
        for (int p = left; p <= right; p++){
            arr[p] = temp[p];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        //straight selection sort
        /*
        int n = nums.size();
        for(int i = 0; i < n;++i){
            int lIdx = i;
            for(int j = i + 1; j < n; ++j){
                if(nums[lIdx] > nums[j]){
                    lIdx = j;
                }
            }
            swap(nums[lIdx], nums[i]);
        }
        return nums;
        */
        vector<int> temp(nums.size());
        mergeSort(nums, 0, nums.size() - 1, temp);
        return nums;
    }
};