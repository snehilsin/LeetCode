/*class Solution {
public:
    bool helper(int  start, string s , vector<int> &memo, unordered_set<string> &wordSet){
        if (start == s.size()) return true;
        if (memo[start] != -1) return memo[start];

        for (int end = start + 1; end <= s.size(); end++){
            string word = s.substr(start, end-start);
            if (wordSet.find(word) != wordSet.end() && helper(end, s, memo, wordSet)){
                memo[start] = 1;
                return true;
            }
        }
        memo[start] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> memo(n, -1);
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return helper(0, s, memo, wordSet);
    }
};*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int maxlen = 0;
        for (auto &word : wordDict){
            maxlen = max(maxlen , (int) word.size());
        }

        vector<bool> dp(n+1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++){
            for (int len = 1; len <= maxlen && len <= i; len++){
                if (!dp[i-len]) continue;

                string word = s.substr(i-len, len);
                if (wordSet.find(word) != wordSet.end() ){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};