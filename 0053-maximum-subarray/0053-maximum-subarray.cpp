class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // brute force approach
        // finding every subarray

       /* int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++){
            int sum = 0;
            for (int j = i; j < nums.size(); j++){
                sum += nums[j];
                maxi = max(maxi, sum);
            }
        }
        return maxi; */

        int maxSum = INT_MIN;
        int currSum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            currSum += nums[i];
            if (maxSum < currSum){
                maxSum = currSum;
            }
            if (currSum < 0){
                currSum = 0;
            }
        }
        return maxSum;
    }
};