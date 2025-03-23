class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int preSum = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++){
            preSum += nums[i];
            int remove = preSum - k;
            cnt += mpp[remove];
            mpp[preSum] += 1;
        }
        return cnt;
        /*Consider the array [1, 2, 3] with k = 3:

Initialize mpp with {0: 1}.​

Start iterating with preSum = 0.​

At index 0 (nums[0] = 1):​

preSum = 1​

remove = 1 - 3 = -2 (not in mpp)​

Update mpp to {0: 1, 1: 1}​

At index 1 (nums[1] = 2):​

preSum = 3​

remove = 3 - 3 = 0 (exists in mpp with frequency 1)​
algoadvance.github.io

Increment cnt by 1​

Update mpp to {0: 1, 1: 1, 3: 1}​

At index 2 (nums[2] = 3):​

preSum = 6​

remove = 6 - 3 = 3 (exists in mpp with frequency 1)​

Increment cnt by 1​

Update mpp to {0: 1, 1: 1, 3: 1, 6: 1}​*/
    }
};