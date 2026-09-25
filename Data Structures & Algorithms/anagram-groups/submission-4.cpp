class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>hashMap;

        for (string str: strs) {
            vector<int>charCount(26, 0);
            for (char c: str) {
                charCount[c - 'a']++;
            }

            string hashKey = to_string(charCount[0]);
            for (int i = 1; i < 26; i++) {
                hashKey += ',' + to_string(charCount[i]);
            }
            hashMap[hashKey].push_back(str);
        }

        vector<vector<string>>result;
        for (auto item: hashMap) {
            result.push_back(item.second);
        }
        return result;
    }
};