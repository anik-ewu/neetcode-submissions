class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1Len = s1.size();
        if (s1.size() > s2.size()) return false;

        for (int i = 0; i <= s2.size() - s1Len; i++) {
            string str = s2.substr(i, s1Len);
            vector<int>frequency(26, 0);
            for (char ch: s1) {
                frequency[ch-'a']++;
            }
            for (char ch: str) {
                frequency[ch-'a']--;
            }

            bool isApermutation = true;
            for (char ch: str) {
                if (frequency[ch - 'a'] != 0) {
                    isApermutation = false;
                    break;
                }
            }
            if (isApermutation) {
                return true;
            }
        }
        return false;
    }
};
