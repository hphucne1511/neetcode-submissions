class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        for(int n : asteroids){
            if(n < 0){
                if(s.empty() || s.back() < 0) s.push_back(n);
                else{
                    while(!s.empty() && s.back() > 0 && s.back() < abs(n)){
                        s.pop_back();
                    }
                    if(s.empty() || s.back() < 0) s.push_back(n);
                    else if(s.back() == abs(n)) s.pop_back();
                }
            }else{
                s.push_back(n);
            }
        }
        return s;
    }
};