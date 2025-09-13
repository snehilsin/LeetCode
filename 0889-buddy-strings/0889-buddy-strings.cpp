class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length()) return false;

        if ( s == goal){
            // check for atleast one dup
            unordered_set<char> st;
            for(char c : s){
                if (st.find(c) != st.end()){
                    return true;
                }
                st.insert(c);
            }
            return false;
        }


        // mismatch
        vector<int> mismatch;

        for (int i = 0; i < s.length(); i++){
            if (s[i] != goal[i]){
                mismatch.push_back(i);
            }
        }

        // mismatch size should be exactly 2 --> because only one swap we are allowed
        if (mismatch.size() != 2) return false;
        
        // now try to swap
        int i = mismatch[0];
        int j = mismatch[1];

        return s[i] == goal[j] && s[j] == goal[i];
    }
};