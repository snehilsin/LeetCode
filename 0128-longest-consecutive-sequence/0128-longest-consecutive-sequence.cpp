class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int x : nums){
            st.insert(x);
        }

        int res = 0;
        for (int x : nums){
            if (st.find(x) != st.end() && st.find(x-1) == st.end()){
                int curr = x;
                int cnt = 0;
                while (st.find(curr) != st.end()){
                    st.erase(curr);
                    cnt++;
                    curr++;
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
};