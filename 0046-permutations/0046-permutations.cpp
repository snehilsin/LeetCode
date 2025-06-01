class Solution {
public:
    void helper(vector<int> &nums, vector<int> &ds, int freq[], vector<vector<int>> &ans){
        if (ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            if (!freq[i]){
                ds.push_back(nums[i]);
                freq[i] = 1;
                helper(nums, ds, freq, ans);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        int freq[n];
        vector<int> ds;
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++){
            freq[i] = 0;
        }
        helper(nums, ds, freq, ans);
        return ans;
    }
};