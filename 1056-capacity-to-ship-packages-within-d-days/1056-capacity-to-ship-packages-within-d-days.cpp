class Solution {
public:
    int noOfD(vector<int> &weights, int cap){
        int d = 1;
        int load = 0;
        int n = weights.size();
        for (int i = 0; i < n; i++){
            if (load + weights[i] > cap){
                d += 1;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while (low <= high){
            int mid = low + (high - low)/2;
            if (noOfD(weights, mid) <= days){
                high = mid -1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};