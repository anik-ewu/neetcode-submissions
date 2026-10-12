class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> hashMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hashMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto& values = hashMap[key];
        int lo = 0;
        int hi = (int)values.size() - 1;
        string result = "";

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (values[mid].first <= timestamp) {
                result = values[mid].second;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return result;
    }
};
