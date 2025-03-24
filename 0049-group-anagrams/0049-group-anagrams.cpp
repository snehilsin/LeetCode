class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // ["eat", "tea", "tan", "ate", "nat", "bat"]
        /* mp = {
            "aet" : ["eat", "tea", "ate"],
            "ant" : ["tan", "nat"],
            "abt" : ["bat"]
            } */

            // intuition - group the words using map key
            // push the key values into the resultant vector

            unordered_map<string, vector<string>> mp;

            for (auto x : strs){
                string key = x;
                sort(key.begin(), key.end());
                mp[key].push_back(x);
            }
            vector<vector<string>> ans;
            for (auto x : mp){
                ans.push_back(x.second);
            }
            return ans;
    }
};