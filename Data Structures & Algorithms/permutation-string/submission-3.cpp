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

        for (int i = 0; i < n; i++) {
            freqs[s1[i]]++;
            freqs2[s2[i]]++;
        }
        if (freqs == freqs2) {
            return true;
        }

        int j = 0;
        for (int i = n; i < m; i++) {
            freqs2[s2[i]]++;
            freqs2[s2[j]]--;
            if (freqs2[s2[j]] == 0) {
                freqs2.erase(s2[j]);
            }
            j++;
            if (freqs == freqs2) {
                return true;
            }
        }
        return false;
    }
};
