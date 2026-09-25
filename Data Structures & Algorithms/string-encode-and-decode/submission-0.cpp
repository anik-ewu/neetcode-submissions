class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString = "";
        for (string str: strs) {
            int len = str.size();
            string numToStr = to_string(len);
            string newItem = numToStr + '#' + str;
            encodedString += newItem;
        }
        return encodedString;
    }

    vector<string> decode(string s) {
        int n = s.size();
        vector<string>decodedStrings;
        for (int i = 0; i < n; i++) {
            int len = 0;
            while (s[i] != '#') {
                len = len * 10;
                len += s[i] - '0';
                i++;
            }
            i++;
            string decodedString = "";
            while (len--) {
             decodedString += s[i++];   
            }
            i--;
            decodedStrings.push_back(decodedString);
        }
        return decodedStrings;
    }
};
//3#abc4#abcd