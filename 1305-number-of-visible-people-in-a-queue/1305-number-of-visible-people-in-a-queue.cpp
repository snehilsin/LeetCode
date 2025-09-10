class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        // [10,6, 8, 5, 11, 9]
        // [3, 1, 2, 1, 1, 0]
        // st -> 11 > 9 1
        // st -> 11
        // st-> 11 5 

        int n = heights.size();
        vector<int> ans(n, 0);
        stack<int> st;
        st.push(heights[n-1]);
        for (int i = n-2; i >= 0; i--){
            int count = 0;
            while (!st.empty() && heights[i] > st.top()){
                st.pop();
                count++;
            }

            if (!st.empty()){
                count++;
            }
            ans[i] = count;
            st.push(heights[i]);
        }

        return ans;
    }
};