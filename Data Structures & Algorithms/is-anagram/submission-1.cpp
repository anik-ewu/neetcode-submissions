class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>countChar(26, 0);

        if (s.size() != t.size()) {
            return false;
        }

        for (int i = 0; i < s.size(); i++) {
            countChar[s[i]-'a']++;
            countChar[t[i]-'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (countChar[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
