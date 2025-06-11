class Solution {
public:
    int fun(vector<int> &nums, int maxSum){
        int n = nums.size();
        int partitions = 1;
        long long sum = 0;
        for (int i = 0; i < n; i++){
            if (sum + nums[i] <= maxSum){
                sum += nums[i];
            } else {
                partitions++;
                sum = nums[i];
            }
        }
        return partitions;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high){
            int mid = low + (high - low)/2;
            int part = fun(nums, mid);
            if (part > k){
                // mid is smaller than our req ans
                low = mid + 1;
            } else {
                high = mid -1;
            }
        }
        return low;
    }
};