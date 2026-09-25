class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>hashMap;
        for (int num: nums) {
            hashMap[num]++;
        }

        priority_queue<pair<int, int>>pq;
        for (auto item: hashMap) {
            int num = item.first;
            int frequency = item.second;
            pq.push({frequency * -1, num});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int>frequentElements;
        while (!pq.empty()) {
            int num = pq.top().second;
            pq.pop();
            frequentElements.push_back(num);
        }
        return frequentElements;
    }
};
