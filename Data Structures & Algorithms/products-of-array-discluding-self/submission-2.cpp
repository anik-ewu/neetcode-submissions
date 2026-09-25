class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int countZeors = 0;
        int n = nums.size();
        vector<int>res(n, 0);
        int productOfAllNums = 1;
        for (int i = 0; i < n ; i++) {
            if (nums[i])
                productOfAllNums *= nums[i];
            else 
                countZeors++;
        }

        if (countZeors > 1) {
            return res;
        }
        else if (countZeors == 1) {
            for (int i = 0; i < n; i++) {
                if(!nums[i]) {
                    res[i] = productOfAllNums;
                }
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                    res[i] = productOfAllNums / nums[i];
            }
        }
        return res;
    }
};
