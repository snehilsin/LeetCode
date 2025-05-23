class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // brute force approach --> check every possible pair of buying and then selling day

/*
        int maxProfit = 0;
        int n = prices.size();

        for ( int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                int profit = prices[j] - prices[i];
                maxProfit = max(maxProfit, profit);
            }
        }
        return maxProfit; */


        // optimal approach -- keep track of min price as well as max profit

       int maxPro = 0;
       int mini = prices[0];

       for (int i = 1; i < prices.size(); i++){
        int currProfit = prices[i] - mini;
        maxPro = max(maxPro, currProfit);
        mini = min(mini, prices[i]);
       }
       return maxPro;
    }
};