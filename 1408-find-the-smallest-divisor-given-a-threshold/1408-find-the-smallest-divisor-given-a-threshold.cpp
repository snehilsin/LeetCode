class Solution {
public:
    int sumByD(vector<int> &nums, int div){
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            sum += ceil((double) (nums[i]) / (double) (div));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        if (n > threshold) return -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if (sumByD(nums, mid) <= threshold){
                // search for more smaller div
                high = mid -1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};