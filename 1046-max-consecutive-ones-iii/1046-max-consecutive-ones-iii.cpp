class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int maxlen = 0;
        int zeroCnt = 0;
        while (right < nums.size()){
            if (nums[right] == 0){
                zeroCnt++;
            }
            while (zeroCnt > k){
                if (nums[left] == 0){
                    zeroCnt--;
                }
                left++;
            }
            maxlen = max(maxlen , right - left + 1);
            right++;
        }
        return maxlen;
    }
};