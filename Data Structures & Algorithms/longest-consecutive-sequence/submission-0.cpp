class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int>hashMap;
        for (int num: nums) {
            hashMap[num] = 1;
        }

        int longestSequence = 0;    
        for (int num: nums) {
            if (hashMap[num] != -1) {
                int value = num + 1;
                int currentSequence = 1;
                hashMap[num] = -1;
                while (hashMap[value] == 1) {
                    hashMap[value] = -1;
                    value++;
                    currentSequence++;
                }
                
                value = num - 1;
                while (hashMap[value] == 1) {
                    hashMap[value] = -1;
                    value--;
                    currentSequence++;
                }

                longestSequence = max(longestSequence, currentSequence);
            }
        }
        return longestSequence;
    }
};
