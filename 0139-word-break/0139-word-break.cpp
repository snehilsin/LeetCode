class Solution {
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
};