class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort both the strings and check if they are same or not
       /* int n1 = s.length();
        int n2 = t.length();
        if (n1 != n2) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t; */

        // better approach - using two counting arrays
        int count1[256] = {0};
        int count2[256] = {0};
        if (s.length() != t.length()) return false;

        for (int i = 0; i < s.length(); i++){
            count1[s[i]]++;
            count2[t[i]]++;
        }
        for (int i = 0; i < 256; i++){
            if (count1[i] != count2[i]){
                return false;
            }
        }
        return true;
    }
};