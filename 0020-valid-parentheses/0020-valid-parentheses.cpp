class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mpp = { {')', '('}, {'}', '{'}, {']', '['}};
        stack<char> st;
        for (char c : s){
           if (mpp.find(c) == mpp.end()){
            st.push(c);
           } else if (!st.empty() && mpp[c] == st.top()){
            st.pop();
           } else{
            return false;
           }
        }
        return st.empty();
    }
};