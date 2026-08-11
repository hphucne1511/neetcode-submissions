class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size() - 1, count = 0;
        while(l <= r){
            count++;
            int remain = limit - people[r--];
            if(l <= r && remain >= people[l]) l++;
        }
        return count;
    }
};