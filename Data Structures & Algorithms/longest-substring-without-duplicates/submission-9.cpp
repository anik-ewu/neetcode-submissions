class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>characterHasSeen(500, 0);
        int longestSubtring = 0;

        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            int charIndex = s[right];
            characterHasSeen[charIndex]++;
            while(characterHasSeen[charIndex] > 1) {
                characterHasSeen[s[left]]--;
                left++;
            }

            int currentLength = right - left + 1;
            longestSubtring = max(longestSubtring, currentLength);
        }

        return longestSubtring;
    }
};
