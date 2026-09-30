class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maximumProfit = 0;
        int minimumValue = INT_MAX;
        for (int price: prices) {
            minimumValue = min(minimumValue, price);
            int currentProfit = price - minimumValue;
            maximumProfit = max(maximumProfit, currentProfit);
        }
        return maximumProfit;
    }
};
