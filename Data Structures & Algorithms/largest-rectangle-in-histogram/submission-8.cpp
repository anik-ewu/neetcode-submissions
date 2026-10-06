class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        stack<int>st;
        vector<int>indexOfMinPrefix(n, 0);
        for (int i = 0; i < n; i++) {
                while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
                if (st.empty()) {
                    indexOfMinPrefix[i] = -1;
                }
                else {
                    indexOfMinPrefix[i] = st.top();
                }
                st.push(i);
        }
        while (!st.empty()) st.pop();

        vector<int>indexOfMinSuffix(n, n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if (st.empty()) {
                indexOfMinSuffix[i] = n;
            }
            else {
                indexOfMinSuffix[i] = st.top();
            }
            st.push(i);
        }

        int maximumRectangle = 0;
        for (int i = 0; i < n; i++) {
            int left = indexOfMinPrefix[i] + 1;
            int right = indexOfMinSuffix[i] - 1;
            int value = (right - left + 1) *  heights[i];
            maximumRectangle = max(maximumRectangle, value);
        }

        return maximumRectangle;
    }
};
