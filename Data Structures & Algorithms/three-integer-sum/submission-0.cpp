class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>>tempResult;
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;
            int target = nums[i] * -1;
            while (j < k) {
                int currSum = nums[j] + nums[k];
                if (currSum == target) {
                    tempResult.insert({nums[i], nums[j], nums[k]});
                }
                if (currSum > target) {
                    k--;
                }
                else {
                    j++;
                }
            }
        }

        vector<vector<int>> triplets;
        for (auto item: tempResult) {
            triplets.push_back(item);
        }
        return triplets;
    }
};
