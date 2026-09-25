class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int n = s.size();
        int longestSubstring = 0;
        vector<int>charFrequency(500, 0);
        
        for (int i = 0; i < n; i++) {
            charFrequency[s[i]]++;
            if (charFrequency[s[i]] > 1) {
                while (s[l] != s[i]) {
                    charFrequency[s[l]]--;
                    l++;
                }
                charFrequency[s[l]]--;
                l++;
            }
            longestSubstring = max(longestSubstring, i - l + 1);

        }
        return longestSubstring;
    }
};
