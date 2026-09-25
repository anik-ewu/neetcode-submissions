class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>hashMap;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            hashMap[nums[i]]++;
        }

        priority_queue<pair<int,int>>pq;
        for (auto item: hashMap) {
            pq.push({item.second * -1, item.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int>result;
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
