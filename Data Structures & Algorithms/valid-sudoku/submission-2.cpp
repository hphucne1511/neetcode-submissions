class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Sử dụng mảng bool hoặc unordered_set để đánh dấu
        // rows[9], cols[9], boxes[9] mỗi cái lưu trạng thái của 9 hàng/cột/ô
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                int num = board[i][j] - '1'; // Chuyển '1'-'9' thành 0-8
                int box_idx = (i / 3) * 3 + (j / 3);

                // Kiểm tra nếu số này đã xuất hiện trong hàng, cột hoặc ô 3x3 chưa
                if (rows[i][num] || cols[j][num] || boxes[box_idx][num]) {
                    return false;
                }

                // Đánh dấu đã xuất hiện
                rows[i][num] = true;
                cols[j][num] = true;
                boxes[box_idx][num] = true;
            }
        }
        return true;
    }
};