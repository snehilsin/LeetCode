class Solution {
public:
  
    bool isValid(string s) {
       

       /* stack<char> st;
        unordered_map<char, char> mpp = {
            {')' , '('}, {'}', '{' }, {']', '['}
        };
             
        for (char c : s){
            if (mpp.find(c) == mpp.end()){
                // opening parenthesis
                st.push(c);
            } else if (!st.empty() && mpp[c] == st.top()){
                st.pop();
            } else {
                return false;
            }
        }
        return st.empty(); */

       // st --> opening parentheses

       stack<char> st;
       for (char c : s){
          if (c == '(' || c == '{' || c == '['){
            st.push(c);
          } else {
            if (st.empty() || (c ==  ')' && st.top() != '(') || (c == '}' && st.top() != '{') || ( c == ']' && st.top() != '[')){
                return false;
            }
            st.pop();
          }
       }
       return st.empty();
    }
};