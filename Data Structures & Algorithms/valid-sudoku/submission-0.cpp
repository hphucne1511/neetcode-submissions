class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size() != 9 || board[0].size() != 9) return false;
        for(int i = 0;i < 9;i++){
            unordered_set<char> row;
            unordered_set<char> col;
            for(int j = 0;j < 9;j++){
                if(board[i][j] != '.'){
                    if(row.count(board[i][j]) || board[i][j] < '0' || board[i][j] > '9') return false;
                    else row.insert(board[i][j]);
                }
                if(board[j][i] != '.'){
                    if(col.count(board[j][i]) || board[j][i] < '0' || board[j][i] > '9') return false;
                    else col.insert(board[j][i]);
                }
                if(i % 3 == 0 && j % 3 == 0){
                    unordered_set<char> subBox;
                    for(int s = i;s < i + 3;s++){
                        for(int t = j;t < j + 3;t++){
                            if(board[s][t] == '.') continue;
                            if(subBox.count(board[s][t]) || board[s][t] < '0' || board[s][t] > '9') return false;
                            else subBox.insert(board[s][t]);
                        }
                    }
                }
            }
        }
        return true;
    }
};
