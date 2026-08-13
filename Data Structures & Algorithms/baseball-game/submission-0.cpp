class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> record;
        for(string s : operations){
            if(s == "+"){
                int temp = record.top();
                record.pop();
                int sum = temp + record.top();
                record.push(temp);
                record.push(sum);
            }else if(s == "D"){
                record.push(record.top() * 2);
            }else if(s == "C"){
                record.pop();
            }else{
                record.push(stoi(s));
            }
        }
        int score = 0;
        while(!record.empty()){
            score += record.top();
            record.pop();
        }
        return score;
    }
};