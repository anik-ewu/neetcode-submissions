class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col = matrix[0].size();
        int row = matrix.size();
        int left = 0;
        int right = (col * row) - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            int r = mid / col;
            int c = mid % col;
            int currentValue =   matrix[r][c];  
            if (currentValue == target) {
                return true;
            }
            else if (currentValue > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return false;
    }
};
