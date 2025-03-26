class Solution {
public:
    int findMin(vector<int>& nums) {
        //[5, 6, 0, 2, 3]
        // l     i     r
        // l     m,r
        //    m
        //    l  r
        //       m

        // if (nums[mid] >= nums[right])   
        //          then min should be in right half
        //          low = mid + 1
        // else 
        //    high = mid (including mid)

        // ans --> nums[low]

       int n = nums.size();
       int left = 0;
       int right = n-1;
       while (left < right){
        int mid = left + (right - left)/ 2;

        if (nums[mid] >= nums[right]){
             left = mid + 1;
        } else {
            right = mid;
        }
       }
       return nums[left];
    }
};