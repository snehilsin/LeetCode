class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // brute force approach
        // finding every subarray
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++){
            int sum = 0;
            for (int j = i; j < nums.size(); j++){
                sum += nums[j];
                maxi = max(maxi, sum);
            }
        }
        return maxi;
    }
};