class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /*vector<int> nonZeroes;
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] != 0){
                nonZeroes.push_back(nums[i]);
            }
        }

        vector<int> ans(nonZeroes.begin(), nonZeroes.end());
        for(int i = nonZeroes.size(); i < nums.size(); i++){
            ans.push_back(0);
        }

        for(int i = 0; i < ans.size(); i++){
            nums[i] = ans[i];
        } */

        int n = nums.size();
        int left = 0;
        for (int right = 0; right < n; right++){
            if (nums[right] != 0){
                swap(nums[left], nums[right]);
                left++;
            }
        }
    }
};