class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        for (int num: nums) {
            hashMap[num] = 1;
        }

        int longestConsucutiveSequence = 0;

        for (int num: nums) {
            if (hashMap[num] != -1) {
                int val = num + 1;
                int currentLcs = 1;

                while (hashMap[val] == 1) {
                    hashMap[val] = -1;
                    currentLcs++;
                    val++;
                }

                val = num - 1;
                while (hashMap[val] == 1) {
                    hashMap[val] = -1;
                    currentLcs++;
                    val--;
                }

                longestConsucutiveSequence = max(longestConsucutiveSequence, currentLcs);
                 
            }
        }
        return longestConsucutiveSequence;
    }
};
