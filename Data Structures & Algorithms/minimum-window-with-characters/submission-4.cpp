class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (m > n) {
            return "";
        }

        unordered_set<char>charSet;
        unordered_map<char, int>freqs1;
        unordered_map<char, int>freqs2;

        for (int i = 0; i < m; i++) {
            freqs1[t[i]]++;
            charSet.insert(t[i]);
        }

        int i = 0;
        int j = 0;
        int len = INT_MAX;
        int startIndex = -1;
        while (i < n || j < n) {
            bool foundSubstr = true;
            for (char ch: charSet) {
                if (freqs2[ch] < freqs1[ch]) {
                    foundSubstr = false;
                }
            }
            if (foundSubstr == true) {
                if (i - j< len) {
                    len = i - j;
                    startIndex = j;
                }
                freqs2[s[j]]--;
                j++;
            }
            else {
                if (i == n) {
                    break;
                }
                freqs2[s[i++]]++;
            }
        }
        if (startIndex == -1) {
            return "";
        }
        return s.substr(startIndex, len);
    }
};


