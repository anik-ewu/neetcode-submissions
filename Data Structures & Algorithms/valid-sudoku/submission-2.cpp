class Solution {
public:
    //Notes: One pass solution
    bool isValidSudoku(vector<vector<char>>& board) {

        bool rows[9][9] = {}, cols[9][9] = {}, box[9][9] = {};

        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == '.') continue;
                int digit = board[i][j] - '1';
                int b = (i / 3) * 3 + j / 3;
                if (rows[i][digit] || cols[j][digit] || box[b][digit]){
                    return false;
                }
                rows[i][digit] = cols[j][digit] = box[b][digit] = true;
            }
        }
        return true;
    }
};
