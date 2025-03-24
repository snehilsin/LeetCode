class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.length();
        stack<string> st;
        string temp = "";
        for (int i = 0; i < s.length(); i++){
            char ch = s[i];
            if (ch == ' '){
                if (temp != ""){
                    st.push(temp);
                }
                temp = "";
            } else {
                temp += ch;
            }
        }
        // last word
        if (temp != ""){
            st.push(temp);
        }
        while (!st.empty()){
            ans = ans +  st.top() + " ";
            st.pop();
        }
        ans.pop_back(); // remove last space
        return ans;

    }
};