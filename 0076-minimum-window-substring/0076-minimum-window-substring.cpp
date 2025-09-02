class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mpp;
        int n = s.length();
        int m = t.length();
        int count = 0;
        int start = -1;
        int minLen = INT_MAX;
        int l = 0;
        int r = 0;
        for (char ch : t){
            mpp[ch]++;
        }

        while (r < n){
            if (mpp[s[r]] > 0) count++;
            mpp[s[r]]--;

            while (count == m){
                if ((r-l+1) < minLen){
                    minLen = r - l + 1;
                    start = l;
                }
                mpp[s[l]]++;
                if (mpp[s[l]] > 0) count--;
                l++;
            }
            r++;
        }
        if (start == -1){
            return "";
        }
        return s.substr(start, minLen);
    }
};