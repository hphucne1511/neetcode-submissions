class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> container;
        for(int i : nums){
            if(container.contains(i)) return true;
            container.insert({i, 0});
        }
        return false;
    }
};