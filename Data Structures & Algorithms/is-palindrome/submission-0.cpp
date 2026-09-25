class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0; 
        int r = s.size() - 1;
        int len = s.size();
        while (l < r) {
            while (l < len && !(iswalnum(s[l]))) {
                l++;
            }
            while (r >= 0 && !(iswalnum(s[r]))) {
                r--;
            }

            if (l < r && tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
