class Solution {
public:
    long long calculateTotalHrs(vector<int> &piles, int hourly){
        long long totalH = 0;
        int n = piles.size();
        for (int i = 0; i < n; i++){
            totalH += ceil((double) (piles[i]) / (double) (hourly));
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;
        long long high = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while (low <= high){
            long long mid = low + (high - low)/2;
            long long totalH = calculateTotalHrs(piles, mid);
            if (totalH <= h){
                ans = mid;
                // search for more smaller hourly rates
                high = mid -1;
            } else {
                // if totalH > h that means you need to search for greater hourly rates
                low = mid + 1;
            }
        }
        return ans;
    }
};