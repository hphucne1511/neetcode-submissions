class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1, count = 0;
        while(i <= j){
            while(i < j && people[j] == limit){
                count++;
                j--;
            }
            if(i < j && people[i] + people[j] <= limit){
                count++;
                j--;
                i++;
            }else if(i < j && people[i] + people[j] > limit){
                count++;
                j--;
            }
            if(i == j){
                count++;
                break;
            }
        }
        return count;
    }
};