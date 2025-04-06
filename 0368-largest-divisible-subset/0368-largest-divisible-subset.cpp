class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp ( n, 1);
        vector<int> parent( n, -1);
        int maxLen = 1;
        int endIndex = 0;
        sort(nums.begin(), nums.end());

        for ( int i = 1; i < n; i++){
            for ( int j = 0; j < i; j++){
                if ( nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i]){
                    dp[i] = 1 + dp[j];
                    parent[i] = j;
                }
            }
            if ( dp[i] > maxLen){
                maxLen = dp[i];
                endIndex = i;
            }
        }
        vector<int> LDS;
            for ( int i = endIndex; i >= 0; i = parent[i]){
                LDS.push_back(nums[i]);
                if ( parent[i] == -1) break;
            }
            reverse(LDS.begin(), LDS.end());
            return LDS;
    }
};