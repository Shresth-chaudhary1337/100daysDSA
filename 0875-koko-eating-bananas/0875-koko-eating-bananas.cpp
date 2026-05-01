class Solution {
public:
    long long findHours(vector<int>& piles, int k) {
        long long hours = 0;
        for (int p : piles) {
            hours += (p + k - 1) / k; // ceil(p/k)
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long hours = findHours(piles, mid);

            if (hours <= h) {
                ans = mid;
                high = mid - 1; // try smaller k
            } else {
                low = mid + 1; // need bigger k
            }
        }

        return ans;
    }
};