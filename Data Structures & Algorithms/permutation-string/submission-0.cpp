class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n = s1.size();
        int m = s2.size();

        if (n > m) {
            return false;
        }
        
        unordered_map<char, int>freqs;
        unordered_map<char, int>freqs2;

        for (char ch : s1) {
            freqs[ch]++;
        }

        int j = 0;
        for (int i = 0; i < m; i++) {
            freqs2[s2[i]]++;
            if (i >= n) {
                freqs2[s2[j]]--;
                j++;
            }

            bool containsPermutation = true;    
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (freqs[ch] != freqs2[ch]) {
                    containsPermutation = false;
                }
            }
            if (containsPermutation) {
                return true;
            }
        }
        return false;
    }
};
