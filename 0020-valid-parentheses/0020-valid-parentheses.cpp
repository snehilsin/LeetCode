class Solution {
public:
    bool isValid(string s) {
        //stack<char> st;
        // in st, push opening parentheses
       /*  unordered_map<char, char> mpp = { {')', '('}, {'}', '{'}, {']', '['}};

        for (char c : s){
            if (mpp.find(c) == mpp.end()){
                // an opening parentheses
                st.push(c);
            } else if (!st.empty() && mpp[c] == st.top()){
                st.pop();
            } else {
                return false;
            }
        }
        return st.empty(); */

        stack<char> st;
        for (char c : s){
            if ( c == '(' || c == '{' || c =='['){
                st.push(c);
            } else {
                if (st.empty() || ( c == ')' && st.top() != '(') || (c == '}' && st.top() != '{') || ( c == ']' && st.top() != '[')){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};