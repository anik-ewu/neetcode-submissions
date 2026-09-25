class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int res = 0;
        int n = nums.size();

        for (int i = 0; i < 32; i++) {
            int mask = 1 << i;

            int x = 0;
            for (int num: nums) {
                if (num & mask) {
                    x++;
                }
            }

            int y = 0;
            for (int num = 1; num < n; num++) {
                if (num & mask) {
                    y++;
                }
            }

            if (x > y) {
                res |= mask;
            }
        }
        return res;
    }
};

