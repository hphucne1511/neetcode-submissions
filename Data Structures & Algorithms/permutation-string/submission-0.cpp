class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> count;
        for(char c : s1){
            count[c]++;
        }
        int k = s1.size();
        unordered_map<char, int> tempC;
        for(int r = 0; r < k; r++){
            tempC[s2[r]]++;
        }
        if(tempC == count) return true;
        for(int r = k; r < s2.size(); r++){
            tempC[s2[r]]++;
            if(!--tempC[s2[r - k]]) tempC.erase(s2[r - k]);
            if(tempC == count) return true;
        }
        return false;
    }
};
