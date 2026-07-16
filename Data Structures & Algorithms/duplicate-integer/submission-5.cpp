class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> container;
        for(int num : nums){
            if(container.count(num)) return true;
            container.insert(num);
        }
        return false;
    }
};