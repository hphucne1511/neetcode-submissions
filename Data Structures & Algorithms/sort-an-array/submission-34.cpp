class Solution {
public:
    void mergeSort(vector<int>& arr, int left, int right){
        int mid = left + ((right - left) >> 1);
        if (left >= right) return;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);

    }
    void merge(vector<int>& arr, int left, int mid, int right){
        vector<int> temp;
        int i = left, j = mid + 1;
        while(i <= mid && j <= right){
            if(arr[i] < arr[j]){
                temp.push_back(arr[i]);
                i++;
            }else{
                 temp.push_back(arr[j]);
                j++;
            }
        }
        while(i <= mid){
            temp.push_back(arr[i]);
            i++;
        }
        while(j <= right){
            temp.push_back(arr[j]);
            j++;
        }
        for(int k = 0; k < temp.size();k++){
            arr[k + left] = temp[k];
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
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};