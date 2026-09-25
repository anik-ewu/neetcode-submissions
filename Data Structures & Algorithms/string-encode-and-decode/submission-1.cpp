class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString = "";
        for (string str: strs) {
            encodedString += to_string(str.size()) + '#' + str;
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
            decodedStrings.push_back(s.substr(i, len));
            i = i + len - 1;
        }
        return decodedStrings;
    }
};
//3#abc4#abcd