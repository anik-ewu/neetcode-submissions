class TimeMap {
public:
    unordered_map<string, map<int, string>>hashMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hashMap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (hashMap.find(key) == hashMap.end()) {
            return "";
        }

        string res = "";
        
        auto item = hashMap[key].upper_bound(timestamp);
        if (item != hashMap[key].begin()) {
            return prev(item)->second;
        }
        return res;
        
        /*for (auto item: hashMap[key]) {
            if (item.first <= timestamp) {
                res = item.second;
            }
            else {
                break;
            }
        }
        return res;*/
    }
};
