class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // brute force approach
       /* for (int i = 0; i < nums.size(); i++){
            for (int j = i + 1; j < nums.size(); j++){
                if (nums[i] + nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {-1, -1}; */

        // better approach - map
       unordered_map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return { -1, -1}; 


     // sorting + two pointers
    /* sort(nums.begin(), nums.end());
     int left = 0;
     int right = nums.size()-1;
     while (left < right){
        int sum = nums[left] + nums[right];
        if (sum == target){
            return {left, right};
        } else if (sum < target){
            left++;
        } else {
            right--;
        }
     }
     return {-1, -1}; */
    } 
};