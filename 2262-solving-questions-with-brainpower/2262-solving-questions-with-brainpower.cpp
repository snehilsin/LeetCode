class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), 0);

        for ( int i = questions.size()-1; i >= 0; i--){
            int in = i + questions[i][1] + 1;
            if (in < questions.size()){
                dp[i] = dp[in] + questions[i][0];
            } else{
                dp[i] = questions[i][0];
            }

            if (i < questions.size() - 1){
                dp[i] = max(dp[i+1], dp[i]);
            }
        }
        return dp[0];
    }
};