class Solution {
public:
    bool isValid(string s) {
        // I/p - "()"
        // O/P - true

        // I/P - "() {} []"
        // O/p - true

        // I/P - "{]"
        // O/P - false

        // stack 
        // unordered_map
        // map --> ")" : "(", "}" : "{", "]" : "["
        // st --> push opening brackets

        // "()"
        // st -> (
        // ) --> key --> map or not --> whether it is equal to my st's top
        // pop
        // st --> empty 
        // valid


        // "(())"
        // st --> ( (
        // ) --> (  --> st pop
        //  st -(
        // )  --> check in map for value --> pop
        // EMPTY --> return true

        // "(()}"
        // st --> ( (
       // check map for its value --> ( == st.top --> pop (
        // }  --> {  not equal to my st top --> return false

        stack<char> st;
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
        return st.empty();

    }
};