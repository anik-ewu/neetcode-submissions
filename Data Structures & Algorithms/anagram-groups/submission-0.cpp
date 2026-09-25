class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>hashMap;

        for (string str: strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            hashMap[sortedStr].push_back(str);
        }

        vector<vector<string>>res;
        for (auto anagrams: hashMap) {
            vector<string>currentRes;
            for(string str: anagrams.second) {
                currentRes.push_back(str);
            }
            res.push_back(currentRes);
        }
        return res;
    }
};
