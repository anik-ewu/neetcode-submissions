class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,bool>hasMap;
        for (int num: nums) {
            if (hasMap.find(num) != hasMap.end()) {
                return true;
            }
            hasMap[num] = true;
        }
        return false;
    }
};
