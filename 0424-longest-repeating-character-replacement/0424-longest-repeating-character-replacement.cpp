class Solution {
public:
    int characterReplacement(string s, int k) {
        
        // no of conversions = length of string - max(freq of all the chars)
        // so, l - maxf <= k

        unordered_map<char, int> mpp;
        int l = 0;
        int r = 0;
        int n = s.size();

        int maxlen = 0;
        int maxfreq = 0;

        while (r < n){
            mpp[s[r]]++;
            maxfreq = max(maxfreq, mpp[s[r]]);

            while ( (r - l + 1) - maxfreq > k){
                // not valid window
                // shrink
                mpp[s[l]]--;
                if (mpp[s[l]] == 0){
                    mpp.erase(s[l]);
                }
                l++;
            }

            // if valid, update maxlen
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};