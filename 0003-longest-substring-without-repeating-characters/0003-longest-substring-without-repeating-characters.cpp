class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*int n = s.size();
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
        return res; */

        unordered_map<char, int> lastIdx;
        int start = 0;
        int maxlen = 0;
        int n = s.length();
        for (int end = 0; end < n; end++){
            if (lastIdx.find(s[end]) != lastIdx.end()){
                start = max(start, 1 + lastIdx[s[end]]);
            }
            lastIdx[s[end]] = end;
            maxlen = max(maxlen, end - start + 1);
        }
        return maxlen;
    }
};