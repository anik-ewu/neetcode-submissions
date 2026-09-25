class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>hasAlreadySeen;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            int remaining = target - nums[i];
            if (hasAlreadySeen.find(remaining) != hasAlreadySeen.end()) {
                return {hasAlreadySeen[remaining], i};
            }
            hasAlreadySeen[nums[i]] = i;
        }
    }
};
