class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lowF = 0;
        int highF = n-1;
        int lowL = 0;
        int highL = n-1;
        int first = -1;
        int last = -1;
        while (lowF <= highF || lowL <= highL){
            int midF = lowF + (highF - lowF) / 2;
            if (nums[midF] == target){
                first = midF;
                highF = midF -1;
            } else if (nums[midF] < target){
                lowF = midF + 1;
            } else {
                highF = midF -1;
            }

            int midL = lowL + (highL - lowL) / 2;
            if (nums[midL] == target){
                last = midL;
                lowL = midL + 1;
            } else if (nums[midL] < target){
                lowL = midL + 1;
            } else {
                highL = midL - 1;
            }
        }
        return {first, last};
    }
};