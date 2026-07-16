class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> temp;
        for(int i = 0;i < nums.size();i++){
            temp.push_back({nums[i], i});
        }
        sort(temp.begin(), temp.end());
        for(int i = 0,j = temp.size() - 1;i < j;){
            if(temp[i].first + temp[j].first > target) j--;
            else if(temp[i].first + temp[j].first < target) i++;
            else return{min(temp[i].second, temp[j].second), max(temp[i].second, temp[j].second)};
        }
        return {};
    }
};
