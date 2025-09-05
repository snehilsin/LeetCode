class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mpp;
        unordered_map<string, char> mpp2;
        int sz = pattern.size();

        vector<string> str;
        string st = "";
        for (int i = 0; i < s.size(); i++){
            if (s[i] == ' '){
                str.push_back(st);
                st = "";
            } else {
                st += s[i];
            }
        }
        str.push_back(st);

        if (str.size() != sz){
            return false;
        }

        for (int i = 0; i < sz; i++ ){
            if (mpp[pattern[i]] != "" || mpp2[str[i]]){
                if (mpp[pattern[i]] != str[i] || mpp2[str[i]] != pattern[i]){
                    return false;
                }
            } else {
                mpp[pattern[i]] = str[i];
                mpp2[str[i]] = pattern[i];
            }
        }
        return true;
    }
};