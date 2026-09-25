class Solution {
public:
    bool canEatAllBanana(int k, vector<int>& piles, int h) {
        long long totalHoursNeeded = 0;
        for (int i = 0; i < piles.size(); i++) {
            int hours = piles[i]/k + (piles[i] % k != 0);
            totalHoursNeeded += hours;
            if (totalHoursNeeded > h) {
                return false;
            }
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();
        if (!n) {
            return 0;
        }
        
        int biggestPile = 0;
        for (int pile : piles) {
            biggestPile = max(biggestPile, pile);
        }

        int low = 1;
        int high = biggestPile;
        int minimumPerHour = 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (canEatAllBanana(mid, piles, h)) {
                minimumPerHour = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return minimumPerHour;
    }
};
