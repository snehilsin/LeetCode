class Solution {
public:
    void helper(vector<char> &s, int idx, vector<char> &res){
        if (idx >= s.size()){
            return;
        }
        helper(s, idx + 1, res);
        res.push_back(s[idx]);
        
    }
    void reverseString(vector<char>& s) {
        vector<char> res;
        helper(s, 0, res);
        for (int i = 0; i < s.size(); i++){
            s[i] = res[i];
        }
    }
};