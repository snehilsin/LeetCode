class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // break point method 
        // [2, 1, 5, 4, 3, 0, 0]
        // bp --> 1st element which is nums[i] < nums[i+1] , search it from the back

        // bp = 1
        // then find the next greater ele than 1
        // which is 3
        // swap 1 and 3
        // [2, 3, 5, 4, 1, 0, 0]
        // then reverse everything after 3
        // [2, 3, 0, 0, 1, 4, 5]

        int n = nums.size();
        int bp = -1;
        for (int i = n-2; i >= 0; i--){
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

        // find next greater element
        for (int i =n-1; i >=0; i--){
            if (nums[i] > nums[bp]){
                swap(nums[i], nums[bp]);
                break;
            }
        }
        
        // reverse everything after that bp
        reverse(nums.begin() + bp + 1 , nums.end());
        return;

    }
};