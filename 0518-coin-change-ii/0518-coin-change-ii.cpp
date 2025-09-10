class Solution {
public:
    int helper(vector<int> &coins, vector<vector<int>> &dp, int amount, int idx){
        if (idx == 0){
            return (amount % coins[0] == 0) ? 1 :0;
        }
        if (dp[idx][amount] != -1){
            return dp[idx][amount];
        }

        int notTaken = helper(coins, dp, amount, idx-1);
        int taken = 0;
        if (coins[idx] <= amount){
            taken = helper(coins, dp, amount - coins[idx], idx);
        }
        return dp[idx][amount] = taken + notTaken;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount + 1, -1));
        return helper(coins, dp, amount, n-1);
    }
};