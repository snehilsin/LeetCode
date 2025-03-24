class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int mini = prices[0];

        for (int i = 1; i < prices.size(); i++){
            int currProfit = prices[i] - mini;
            maxPro= max(maxPro, currProfit);
            mini = min(mini, prices[i]);
        }
        return maxPro;
    }
};