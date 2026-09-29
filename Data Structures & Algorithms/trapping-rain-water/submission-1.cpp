class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int>prefixMax(n, 0);
        prefixMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], height[i]);
        }

        vector<int>suffixMax(n, 0);
        suffixMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(height[i], suffixMax[i + 1]);
        }

        int totalAmountOfWater = 0;
        for (int i = 1; i < n - 1; i++) {
            int waterInCurrentBlock = min(prefixMax[i], suffixMax[i]) - height[i];
            totalAmountOfWater += waterInCurrentBlock;
        }
        return totalAmountOfWater;
    }
};
