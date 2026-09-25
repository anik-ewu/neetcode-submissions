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
            freqs2[s[i]]++;
            charSet.insert(t[i]);
        }

        if (freqs1 == freqs2) {
            return s.substr(0, m);
        }

        int i = m;
        int j = 0;
        int len = INT_MAX;
        int startIndex = -1;
        while (i <= n) {
            bool foundSubstr = true;
            for (char ch: charSet) {
                if (freqs2[ch] < freqs1[ch]) {
                    foundSubstr = false;
                }
            }
            if (foundSubstr == false && i < n) {
                freqs2[s[i]]++;
                i++;
            }
            else if(foundSubstr == false && i == n) {
                break;
            }
            else {
                if (i - j< len) {
                    len = i - j;
                    startIndex = j;
                }
                freqs2[s[j]]--;
                j++;
            }
        }
        if (startIndex == -1) {
            return "";
        }
        return s.substr(startIndex, len);
    }
};


