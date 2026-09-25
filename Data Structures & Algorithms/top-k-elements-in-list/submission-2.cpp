class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>count;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            count[nums[i]]++;
        }

        vector<vector<int>>freq(len + 1);

        for (auto item: count) {
            freq[item.second].push_back(item.first);
        }

        vector<int>result;
        for (int index = len; index > 0; index--) {
            for (int item: freq[index]) {
                result.push_back(item);
                if (result.size() == k) {
                    return result;
                }
            }
        }
    }
};
