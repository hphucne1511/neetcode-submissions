class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        stack<double> st;
        vector<pair<int, int>> car(n);
        for(int i = 0; i < n; i++){
            car[i] = {position[i], speed[i]};
        }
        sort(car.rbegin(), car.rend());
        for(auto& p : car){
            double time = (double)(target - p.first) / p.second;
            if(!st.empty() && time <= st.top()) continue;
            else st.push(time);
        }
        return st.size();
    }
};
