class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>maxOnLeft(n, 0);
        vector<int>maxOnRight(n, 0);

        int maxValue = 0;
        for (int i = 0; i < n; i++) {
            maxValue = max(maxValue, height[i]);
            maxOnLeft[i] = maxValue;
        }
        
        maxValue = 0;
        for (int i = n - 1; i >= 0; i--) {
            maxValue = max(maxValue, height[i]);
            maxOnRight[i] = maxValue;
        }

        int maxiumWaterArea = 0;
        for (int i = 1; i < n - 1; i++) {
            int minBarHeght = min(maxOnLeft[i], maxOnRight[i]);
            if (minBarHeght > height[i]) {
                maxiumWaterArea += (minBarHeght - height[i]);
            }
        }
        return maxiumWaterArea;
    }
};
