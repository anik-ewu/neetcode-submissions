class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int sizeOfS = s.size();
        int sizeOfT = t.size();

        if (sizeOfS != sizeOfT) {
            return false;
        }
        
        vector<int>countChar(26, 0);

        for (char ch: s) {
            countChar[ch - 'a']++;
        }
        for (char ch: t) {
            countChar[ch - 'a']--;
        }

        for (int value: countChar) {
            if(value) {
                return false;
            }
        }
        return true;
    }
};
