class Solution {
public:
    bool canEatAllBanana(vector<int>& piles, int h, int k) {
        for (int bananas: piles) {
            int timeNeeded = (bananas / k) + (bananas % k != 0);
            h -= timeNeeded;
            if (h < 0) {
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canEatAllBanana(piles, h, mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }

        }
        return lo;
    }
};
