class Solution {
public:
    int findMin(vector<int>& nums) {
        // one of the two halves of the array will always be sorted
        // if arr[low] <= arr[mid] --> left half sorted
        // if arr[mid] <= arr[high] --> right half sorted

        // minimum element will always be the leftmost element in any half

        int low = 0;
        int high = nums.size()-1;
        int ans = INT_MAX;
        while (low <= high){
            int mid = low + (high - low) / 2;
            if (nums[low] <= nums[mid]){
                //left half sorted
                ans = min(ans, nums[low]);
                low = mid + 1;
            } else {
                // right half sorted
                ans = min(ans, nums[mid]);
                high = mid -1;
            }
        }
        return ans;
    }
};