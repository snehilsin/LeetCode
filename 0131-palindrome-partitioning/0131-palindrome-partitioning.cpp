class Solution {
public:
    bool isPalindrome(const string &s, int left, int right){
        while (left < right){
            if (s[left++] != s[right--]){
                return false;
            }
        }
        return true;
    }
    void helper(const string &s, int start, vector<string> &path, vector<vector<string>> &res){
        if (start == s.length()){
            res.push_back(path);
            return;
        }

        for (int end = start + 1; end <= s.length(); end++){
            if (isPalindrome(s, start, end -1)){
                path.push_back(s.substr(start, end -start));
                helper(s, end, path, res);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        helper(s, 0, path, res);
        return res;
    }
};