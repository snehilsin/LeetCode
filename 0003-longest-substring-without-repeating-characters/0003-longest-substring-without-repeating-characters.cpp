class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; i++){
            vector<bool> vis(n, false);
            for (int j = i; j < n; j++){
                if (vis[s[j] - 'a'] == true){
                    break;
                }else {
                    res  = max(res, j- i + 1);
                    vis[s[j] - 'a'] = true;
                }
            }
        }
        return res;
    }
};