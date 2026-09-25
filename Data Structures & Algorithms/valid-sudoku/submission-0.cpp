class Solution {
public:
    
    bool isValidPostion(int x, int y, vector<vector<char>>& board) {
        char currentCell = board[x][y];
        for (int i = 0; i < 9; i++) {
            if (board[i][y] == currentCell && i != x) {
                return false;
            }
        }
        for(int i = 0; i < 9; i++) {
            if (board[x][i] == currentCell && i != y) {
                return false;
            }
        }
        
        int boxX = x - (x % 3);
        int boxY = y - (y % 3);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int tempX = boxX + i;
                int tempY = boxY + j;
                if ((tempX != x || tempY != y) && board[tempX][tempY] == currentCell) {
                    return false;
                    
                } 
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (!isValidPostion(i, j, board)) {
                    return false;
                }
            }
        }
        return true;
    }
};
