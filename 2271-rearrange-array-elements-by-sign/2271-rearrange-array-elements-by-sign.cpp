class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       /* int i = 0;
        int j = 0;
        int n = nums.size();
        vector<int> ans;
        while ( i < n && j < n){
             while ( i < n && nums[i] < 0){
                i++;
             }
             while ( j < n && nums[j] > 0){
                j++;
             }
             // i --> catches positive elements
             // j --> catches negative elements
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            i++;
            j++;
        }
        return ans; */

        // without using extra space
        int pi = 0;
        int ni = 1;
        vector<int> res(nums.size(), 0);

        for (int num : nums){
            if (num > 0){
                res[pi] = num;
                pi +=2;
            } else {
                res[ni] = num;
                ni += 2;
            }
        }
        return res;
    }
};