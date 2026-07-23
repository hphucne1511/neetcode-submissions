class Solution {
public:
    void insertionSort(vector<int>& nums, int begin, int end){
        for(int i = 1; i < nums.size();++i){
            int key = nums[i];
            int j = i - 1;
            while(j >= 0 && nums[j] > key){
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = key; 
        }
    }
    vector<int> bubbleSort(vector<int>& nums){
        for(int i = 0; i < nums.size();i++){
            bool swapped = false;
            for(int j = nums.size() - 1; j > i;j--){
                if(nums[j - 1] > nums[j]){
                    swap(nums[j], nums[j - 1]);
                    swapped = true;
                } 
            }
            if(!swapped) break;
        }
        return nums;
    }
    int partition(vector<int>& nums, int begin, int end){
        int mid = (begin + end) >> 1;
        swap(nums[mid], nums[begin + 1]);

        if(nums[begin] > nums[end]) swap(nums[begin], nums[end]);
        if(nums[begin + 1] < nums[begin]) swap(nums[begin + 1], nums[begin]);
        if(nums[begin + 1] > nums[end]) swap(nums[begin + 1], nums[end]);

        int pivot = nums[begin + 1];
        int i = begin + 1;
        int j = end;
        while(true){
            while(nums[++i] < pivot);
            while(nums[--j] > pivot);
            if(j < i) break;
            swap(nums[i], nums[j]);
        }
        nums[begin + 1] = nums[j];
        nums[j] = pivot;
        return j;
    }
    void quickSort(vector<int>& nums, int begin, int end){
        int size = end - begin + 1;
        if(size <= 2){
            if(end == begin + 1 && nums[begin] > nums[end]) swap(nums[begin], nums[end]);
            return;
        }
        if(size <= 5){
            insertionSort(nums, begin, end);
            return;
        }
        int pivotIdx = partition(nums, begin, end);
        quickSort(nums, begin, pivotIdx - 1);
        quickSort(nums, pivotIdx + 1, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};