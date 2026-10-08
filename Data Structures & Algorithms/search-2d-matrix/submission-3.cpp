class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int m = matrix.size();
        int row = 0;
        int col = (n * m) - 1;

        while (row <= col) {
            int mid = (row + col) / 2;
            int r = mid / n;
            int c = mid % n;
            int currentValue =   matrix[r][c];  
            if (currentValue == target) {
                return true;
            }
            else if (currentValue > target) {
                col = mid - 1;
            }
            else {
                row = mid + 1;
            }
        }

        return false;
    }
};
