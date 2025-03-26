class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        stack<string> st;
        string temp = "";
        int n = s.length();
        for (int i = 0; i < n; i++){
             char ch = s[i];
             if (ch == ' '){
                if (temp != ""){
                    st.push(temp);
                }
                temp = "";
             } else{
             temp += ch;
             }
        }
        // for the last word
        if (temp != ""){
            st.push(temp);
        }
        while (!st.empty()){
            ans = ans + st.top() + " ";
            st.pop();
        }
        // to handle last space
        ans.pop_back();
        return ans;
    }
};