class Solution {
public:
    int characterReplacement(string s, int k) {
        int longestSubstring = 0;
        for (char ch = 'A'; ch <= 'Z'; ch++) {
            int canChange = k;
            int left = 0;
            int right;
            for (right = 0; right < s.size(); right++) {
                if (s[right] == ch) {
                    longestSubstring = max(longestSubstring, right - left + 1);
                }
                else if (canChange) {
                    longestSubstring = max(longestSubstring, right - left + 1);
                    canChange--;
                    continue;
                }
                else {
                    while(left < right && s[left] == ch) {
                        left++;
                    }
                    left++;
                }
                longestSubstring = max(longestSubstring, right - left + 1);
            }
        }
        return longestSubstring;
    }
};
