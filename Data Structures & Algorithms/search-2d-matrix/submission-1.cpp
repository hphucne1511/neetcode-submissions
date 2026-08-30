class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1, row = 0;
        while(l <= r){
            row = l + (r - l)/2;
            if(matrix[row][0] == target) return true;
            else if(matrix[row][0] < target) l = row + 1;
            else r = row - 1;
        }
        if(r >= matrix.size()) return false;
        l = 0, row = r, r = matrix[0].size() - 1;
        while(l <= r){
            int m = l + (r - l)/2;
            if(matrix[row][m] == target) return true;
            else if(matrix[row][m] < target) l = m + 1;
            else r = m - 1;
        } 
        return false;
    }
};
