class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // use two pointers to swap a 0 and a non zero number

        int n = nums.size();
        int left = 0;
        for ( int right = 0; right < n; right++){
            if (nums[right] != 0){
                swap(nums[right], nums[left]);
                left++;
            }
        }
    }
};