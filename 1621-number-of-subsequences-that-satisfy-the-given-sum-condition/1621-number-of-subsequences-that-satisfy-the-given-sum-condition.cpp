class Solution {
public:
const int MOD = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int l = 0, r = nums.size()-1;
        vector<int> p2(nums.size());
        p2[0] = 1;
        for ( int i = 1; i < nums.size(); i++){
            p2[i] = (p2[i-1] * 2) % MOD;
        }
        while ( l <= r){
            if ( nums[l] + nums[r] <= target){
                ans += p2[r-l];
                ans %= MOD;
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};