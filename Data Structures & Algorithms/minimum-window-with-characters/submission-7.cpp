class Solution {
public:

    //Time complexity : O(m) + log n * O(n) * O (128) = O(n log n)
    // where n = s.size and m = t.size 

    bool checkFrequency(vector<int>&sFrequency, vector<int>& tFrequency) {
        for (int i = 0; i < 128; i++) {
            if (tFrequency[i] > sFrequency[i]) return false;
        }
        return true;
    }

    vector<int> isValidSubtringLength(int len, string&s, vector<int>& countT) {
        vector<int>countFrequency(128, 0);
        for (int i = 0; i <len ; i++) {
            countFrequency[s[i]]++;
        }

        if (checkFrequency(countFrequency, countT)) {
            return {0, len - 1};
        }

        int left = 0;
        for (int i = len; i < s.size(); i++) {
            countFrequency[s[i]]++;
            countFrequency[s[left++]]--;
            if (checkFrequency(countFrequency, countT)) {
                return {i-len + 1, i};
            }
        }

        return {-1, -1};
    }
    string minWindow(string s, string t) {
        int lo = t.size();
        int hi = s.size();

        vector<int>countT(128, 0);
        for (char ch: t) {
            countT[ch]++;
        }
    
        int left = -1, right = - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            vector<int>result = isValidSubtringLength(mid, s, countT);
            // cout<<mid <<" "<<result[0]<<enld;
            if (result[0] != -1) {
                hi = mid - 1;
                left = result[0];
                right = result[1];
            }
            else {
                lo = mid + 1;
            }
        }

        if (left == -1) return "";

        string finalSubstring = s.substr(left, right - left + 1);
        return finalSubstring;
    }
};


