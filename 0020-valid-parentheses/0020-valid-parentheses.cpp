class Solution {
public:
    bool isValid(string s) {
        // map + stack
        // map --> key = closing parentheses, value --> open parentheses
        // st has only open parentheses --> when closing parentheses come, use it as a key to find valid open parenthesis
        // if the two parentheses are not valid, then return false

        stack<char> st;
        unordered_map<char, char> mpp = {{')', '('}, 
                                         {']', '['},
                                         {'}', '{'}
                                        }; // closing , opening
        for (char c : s){
             if (mpp.find(c) == mpp.end()){
                st.push(c);
             } else if (!st.empty() && mpp[c] == st.top()){
                st.pop();
             } else {
                return false;
             }

        }
        return st.empty();
    }
};