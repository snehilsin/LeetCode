class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*unordered_map<int, int> mp;
        for (auto num : nums){
            mp[num]++;
        }
        for (auto x : nums){
            if (x.second == 1){
                return x.first;
            }
        }
        return -1; */

       /* sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i+= 2){
            if (nums[i] != nums[i-1]){
                return nums[i-1];
            }
        }
        return nums[nums.size()-1]; */
        int ans = 0;
        for (auto x : nums){
            ans = ans ^ x;
        }
        return ans;
    }
};