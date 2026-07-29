class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       /* set<int>st;
        for (int x : nums){
            st.insert(x);
        }

        int i = 0;
        for(int x : st){
            nums[i] = x;
            i++;
        }
        return st.size(); */

        int i = 0;
        int n = nums.size();
        for (int j = 0; j < n; j++){
            if (nums[i] != nums[j]){
                i++;
            }
            nums[i] = nums[j];
        }
        return i+1;
    }
};