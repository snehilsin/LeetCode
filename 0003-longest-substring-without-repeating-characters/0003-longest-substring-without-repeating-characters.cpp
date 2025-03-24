class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       /* int n = s.length();
        int maxlen = 0;
        for (int i = 0; i < n; i++){
            unordered_set<char> uniqueChars;
            for (int j = i; j < n; j++){
                if (uniqueChars.find(s[j]) != uniqueChars.end()){
                    break;
                }
                uniqueChars.insert(s[j]);
                maxlen = max(maxlen, (j - i + 1));
            }
        }
        return maxlen; */
        unordered_map<char, int>  lastIdx;
        int maxlen = 0;
        int n = s.length();
        int start = 0;
        for (int end = 0; end < n; end++){
            if (lastIdx.find(s[end]) != lastIdx.end()){
                // repeating char, update start to max(start, 1 + repeating char)
                start = max(start, lastIdx[s[end]] + 1);
            }
            lastIdx[s[end]] = end;
            maxlen = max(maxlen, end - start + 1);
        }
        return maxlen;
    }
};