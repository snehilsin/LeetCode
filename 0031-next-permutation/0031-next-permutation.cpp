class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Break Point Method

        // [2, 1, 5, 4, 3, 0, 0]
        // bp --> 1
        // just next > 1 is 3
        // swap 1 and 3
        // then reverse everything after 3

        int n = nums.size();
        int bp = -1;
        for ( int i = n-2; i >= 0; i--){
            if (nums[i] < nums[i+1]){
                bp = i;
                break;
            }
        }

        // if no bp, then reverse the whole array
        if (bp == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        // find just next greater
        for (int i = n-1; i >= 0; i--){
            if (nums[i] > nums[bp]){
                swap(nums[i], nums[bp]);
                break;
            }
        }
        reverse(nums.begin() + bp + 1, nums.end());
        return;

    }
};