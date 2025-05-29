class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for (int val : nums){
            st.insert(val);
        }

        int res = 0;
        for(int val : nums){
            if (st.find(val) != st.end() && st.find(val-1) == st.end()){
                int curr = val;
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