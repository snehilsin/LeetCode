class Solution {
public:
    void sortColors(vector<int>& nums) {
        // brute force approach
        // sort

       // sort(nums.begin(), nums.end());

       // better approach - count method
      /* int cnt0 = 0;
       int cnt1 = 0;
       int cnt2 = 0;
       for (int i = 0; i < nums.size(); i++){
        if (nums[i] == 0){
            cnt0++;
        } else if (nums[i] == 1){
            cnt1++;
        } else {
            cnt2++;
        }
       }


       for (int i = 0; i < cnt0; i++){
        nums[i] = 0;
       }
       for (int i = cnt0; i < cnt0 + cnt1; i++){
        nums[i] = 1;
       }
       for (int i = cnt0 + cnt1 ; i < nums.size(); i++){
        nums[i] = 2;
       } */

       // dutch national flag algorithm

       int low = 0;
       int n = nums.size();
       int high = n-1;
       int mid = 0;
       while (mid <= high){
        if (nums[mid] == 0){
            swap(nums[mid], nums[low]);
            low++;
            mid++;
        } else if (nums[mid] == 1){
            mid++;
        } else {
            swap(nums[mid], nums[high]);
            high--;
        }
       }

    }
};