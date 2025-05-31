class Solution {
public:
    void findComb(vector<int> & candidates, int target, vector<int> &comb, vector<vector<int>> &ans, int ind){
        if (ind == candidates.size()){
            if (target == 0){
                ans.push_back(comb);
            }
            return;
        }

        if (candidates[ind] <= target){
            comb.push_back(candidates[ind]);
            findComb(candidates, target - candidates[ind], comb, ans, ind); // ind because we might want the same element ex - [2, 3, 6, 7], tar = 7 --> 2, 2, 3 = 7
            comb.pop_back();
        }
        findComb(candidates, target, comb, ans , ind + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int>> ans;
        findComb(candidates, target, comb, ans, 0);
        return ans;
    }
};