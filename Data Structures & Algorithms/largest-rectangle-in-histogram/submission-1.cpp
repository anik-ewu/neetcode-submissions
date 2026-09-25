class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largestArea = 0;
        int n = heights.size();
        stack<pair<int, int>>st;


        for (int i = 0; i < n; i++) {
            int start = i;
            while (!st.empty() && st.top().second > heights[i]) {
                int index = st.top().first;
                int height = st.top().second;
                int range = i - index;
                int area = range * height;
                largestArea = max(largestArea, area);
                start = index;
                st.pop();
            }
            st.push({start, heights[i]});
        }

        while (!st.empty()) {
            int index = st.top().first;
            int height = st.top().second;
            int range = n - index;
            int area = range * height;
            largestArea = max(largestArea, area);
            st.pop();
        }
        return largestArea;
    }
};