class NumMatrix {
public:
    vector<vector<int>> sumMat;
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> mat(row, vector<int>(col));
        for(int i = row - 1; i >= 0; --i){
            for(int j = col - 1; j >= 0; --j){
                if(i == row - 1 && j == col - 1) mat[i][j] = matrix[i][j];
                else if(i == row - 1) mat[i][j] = matrix[i][j] + mat[i][j + 1];
                else if(j == col - 1) mat[i][j] = matrix[i][j] + mat[i + 1][j];
                else mat[i][j] = matrix[i][j] + mat[i][j + 1] + mat[i + 1][j] - mat[i + 1][j + 1];
            }
        }
        sumMat = mat;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int row = sumMat.size();
        int col = sumMat[0].size();
        if(row2 == row - 1 && col2 == col - 1)
            return sumMat[row1][col1];
        else if(row2 == row - 1)
            return sumMat[row1][col1] - sumMat[row1][col2 + 1];
        else if(col2 == col - 1)
            return sumMat[row1][col1] - sumMat[row2 + 1][col1];
        else
            return sumMat[row1][col1] - sumMat[row1][col2 + 1] - sumMat[row2 + 1][col1] +sumMat[row2 + 1][col2 + 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */