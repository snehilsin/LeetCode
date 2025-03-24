class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2]; */

      /*  int n = nums.size();
        unordered_map<int, int> m;

        for (int i = 0; i < n; i++){
            m[nums[i]]++;
        }
        n = n/2;
        for (auto x : m){
            if (x.second > n){
                return x.first;
            }
        }
        return 0; */

       int n = nums.size();
       int count = 0;
       int candidate = -1;

       // first find the candidate
       for (int i = 0; i < n; i++){
        if (count == 0){
            candidate = nums[i];
            count = 1;
        } else if (nums[i] == candidate){
            count++;
        } else {
            count--;
        }
       }

       // validate candidate
       count = 0;
       for (int num : nums){
          if (num == candidate){
            count++;
          }
       }

       // finally return the majority element
       if (count > (n/ 2)){
          return candidate;
       } else {
        return -1;
       }
    }
};