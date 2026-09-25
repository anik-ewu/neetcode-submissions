class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minValue = INT_MAX;

        for (int price: prices) {
            if (price > minValue) {
                maxProfit = max(maxProfit, price - minValue);
            } 
            else {
                minValue = price;
            }
        }
        return maxProfit;
    }
};
