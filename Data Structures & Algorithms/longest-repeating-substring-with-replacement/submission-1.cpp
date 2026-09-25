class Solution {
public:
    int characterReplacement(string s, int k) {
        int longestSubstringLen = 0;
        int n = s.size();
        
        for (char ch = 'A'; ch <= 'Z'; ch++) {
           int j = 0;
           int tempK = k;
           for (int i = 0; i < n; i++) {
                if (s[i] == ch || tempK) {
                    longestSubstringLen = max(longestSubstringLen, i - j + 1);
                    if (s[i] != ch) {
                        tempK--;
                    }
                }
                else {
                    while (s[j] == ch) {
                        j++;
                    }
                    j++;
    
                }
           }
        }
        return longestSubstringLen;
    }
};