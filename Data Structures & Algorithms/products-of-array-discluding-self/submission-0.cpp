class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int countZero = 0;
        long long product = 1;

        for (int num: nums) {
            if (num == 0) {
                countZero++;
                continue;
            }
            product *= 1LL * num;
        }

        int n = nums.size();
        vector<int>productArray(n, 0);
        if (countZero > 1) {
            return productArray;
        }
        if (countZero == 1) {
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0) {
                    productArray[i] = product;
                    break;
                }
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                productArray[i] = product/nums[i];
            }
        }
        return productArray;
    }
};
