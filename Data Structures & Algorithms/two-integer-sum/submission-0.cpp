class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>hashMap;

        for (int i = 0; i < nums.size(); i++) {
            int compliment = target - nums[i];
            if (hashMap.find(compliment) != hashMap.end()) {
                int firstIndex = hashMap[compliment];
                int secondIndex = i;
                return {firstIndex, secondIndex};
            }
            hashMap[nums[i]] = i;
        }
    }
};
