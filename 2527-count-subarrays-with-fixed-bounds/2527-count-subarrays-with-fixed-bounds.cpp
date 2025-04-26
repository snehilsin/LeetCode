class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();

        int bad_idx = -1;  // it will store the values outside the range of [minK, maxK]
        int left_idx , right_idx = -1;

        long long ans = 0;

        for ( int i = 0; i < n; i++){
            if ( nums[i] < minK || nums[i] > maxK){
                bad_idx = i;
            }
            if ( nums[i] == minK){
                left_idx = i;
            }
            if ( nums[i] == maxK){
                right_idx = i;
            }
            int temp = min( left_idx, right_idx) - bad_idx;
            ans += ( temp < 0) ? 0 : temp;
        }
        return ans;
    }
};