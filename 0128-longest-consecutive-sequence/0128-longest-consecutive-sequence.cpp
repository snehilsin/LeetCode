class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;
        for (int num : nums){
            if (!st.count(num-1)){
                int curr = num;
                int streak = 1;

                while(st.count(curr+1)){
                    curr++;
                    streak++;
                }
                longest = max(longest, streak);
            }
            
        }
        return longest;
    }
};