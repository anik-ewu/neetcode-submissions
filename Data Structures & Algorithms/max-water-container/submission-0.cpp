class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0;
        int j = n - 1;
        int containerCapacity = -1;
        while (i < j) {
            int left = heights[i];
            int right = heights[j];

            int capacity = min(right, left) * (j - i);
            containerCapacity = max(containerCapacity, capacity);
            if (left > right) {
                j--;
            }
            else {
                i++;
            }
        }

       return containerCapacity;
    }
};
