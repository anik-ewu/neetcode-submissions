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
        int n = piles.size();
        if (n == 0) return 0;

        int maxBananaInOnePile = 0;
        for (int i = 0; i < n; i++) {
            maxBananaInOnePile = max(maxBananaInOnePile, piles[i]);
        }

        int lo = 1;
        int hi = maxBananaInOnePile;
        int minimumK =-1;
        while (lo <= hi) {
            int mid = (hi + lo) / 2;
            if (canEatAllBanana(piles, h, mid)) {
                minimumK = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }

        }
        return minimumK;
    }
};
