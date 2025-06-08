class Solution {
public:
    bool possible(int day, vector<int> &bloomDay, int m , int k){
        int n = bloomDay.size();
        int cnt = 0;
        int noOfB = 0;
        for ( int i = 0; i < n; i++){
            if (bloomDay[i] <= day){
                cnt++;
            } else {
                noOfB += (cnt / k);
                cnt = 0;
            }
        }
        noOfB += (cnt / k);
        return noOfB >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1LL * k * 1LL;
        int n = bloomDay.size();
        if (val > n) return -1;
        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());
        int low = mini;
        int high = maxi;
        while (low <= high){
            int mid = low + (high - low) / 2;
            if (possible(mid, bloomDay, m, k)){
                // search for more smaller day
                high = mid -1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};