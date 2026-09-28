class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int maximumCapacity = 0;

        while (left < right) {
            int h1 = heights[left];
            int h2 = heights[right];
            int currentCapacity = (right - left) * min(h1, h2);
            maximumCapacity = max(maximumCapacity, currentCapacity);

            if (h1 < h2) {
                left++;
            }
            else {
                right--;
            }

        }

        return maximumCapacity;
    }
};
