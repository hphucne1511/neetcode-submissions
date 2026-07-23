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
    void quickSort(vector<int>& nums, int begin, int end){
        int size = end - begin + 1;
        if(size <= 0) return;
        if(size <= 4){
            insertionSort(nums, begin, end);
            return;
        }
        int pivot = nums[begin];
        int pivotIdx = begin;
        for(int i = begin + 1, j = end; i <= j;){
            if(nums[i] > pivot && nums[j] < pivot){
                swap(nums[i], nums[j]);
            }
            while(i <= j && nums[i] <= pivot) ++i;
            while(i <= j && nums[j] >= pivot) --j;
            if(j < i){
                swap(nums[begin], nums[j]);
                pivotIdx = j;
                break;
            } 
        }
        quickSort(nums, begin, pivotIdx - 1);
        quickSort(nums, pivotIdx + 1, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};