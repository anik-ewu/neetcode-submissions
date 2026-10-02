class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        if (t.size() == 0) return "";

        unordered_map<char, int>countT, window;
        for (char ch: t) {
            countT[ch]++;
        }

        int have = 0, need = countT.size();
        int resStart = 0;
        int resLen = INT_MAX;

        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;

            if (countT.count(c) && window[c] == countT[c]) {
                have++;
            }

            while (have == need) {
                if ((r - l + 1) < resLen) {
                    resLen = r - l + 1;
                    resStart = l;
                }
                window[s[l]]--;
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(resStart, resLen);
    }
};
