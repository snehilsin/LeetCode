class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // MISSING COUNT = ARR[MID] - (MID + 1)
        int low = 0;
        int high = arr.size()-1;
        while (low <= high){
            int mid = low + (high - low)/2;
            int missCnt = arr[mid] - (mid + 1);
            if (missCnt < k){
                low = mid + 1;
            } else {
                high = mid -1;
            }
        }
        return low + k;
    }
};