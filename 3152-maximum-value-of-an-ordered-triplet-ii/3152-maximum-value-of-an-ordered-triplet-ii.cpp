class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
      int n = nums.size();
        vector<int> leftMx(n) , rightMx(n);

        for(int i=1 ; i<n ; i++){
            leftMx[i] = max(leftMx[i-1] , nums[i-1]);
            rightMx[n-i-1] = max(rightMx[n-i] , nums[n-i]);
        }

        long long ans = 0;

        for(int j=1 ; j<n-1 ; j++){
            ans = max(ans , (long long)(leftMx[j] - nums[j])*rightMx[j]);
        }
        return ans;
    }
};