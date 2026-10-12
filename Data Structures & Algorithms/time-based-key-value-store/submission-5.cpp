class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> hashMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hashMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = hashMap.find(key);
        if (it == hashMap.end()) return "";

        auto& vec = it->second;    
        int lo = 0;
        int hi = (int)vec.size() - 1;
        int ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (vec[mid].first <= timestamp) {
                ans = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return ans == -1 ? "" : vec[ans].second;
    }
};
