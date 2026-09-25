class Solution {
public:
    bool isValidSudokuPosition(int x, int y, int row, int col, vector<vector<char>>& board) {

        char currentValue = board[x][y];
        for (int  i = 0; i < 9; i++) {
            if (i != x && board[i][y] == currentValue) return false;
        }
        
        for (int  i = 0; i < 9; i++) {
            if (i != y && board[x][i] == currentValue) return false;
        }

        int gridRow = (x / 3) * 3;
        int girdCol = (y / 3) * 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i + gridRow != x || j + girdCol != y) {
                    if (board[i + gridRow][j + girdCol] == currentValue) {
                        return false;
                    }
                }
            }
        }
        return true;

    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == '.') continue;
                if (!isValidSudokuPosition(i, j, row, col, board)) {
                    return false;
                }
            }
        }
        return true;
    }
};
