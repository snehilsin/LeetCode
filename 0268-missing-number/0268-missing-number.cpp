class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Brute force approach 
       /* int n = nums.size();
        for (int i = 1; i <= n; i++){
            int flag = 0;
            for (int j = 0; j < n; j++){
                if (nums[j] == i){
                    flag = 1;
                    break;
                }
            }
            if (flag == 0){
                return i;
            }
        }
        return -1; */

        // Better Approach --> Hashing 
       /* int n = nums.size();
        vector<int> hash(n+1, 0);
        for (int i = 0; i < n; i++){
            hash[nums[i]]++;
        }
        for (int i = 0; i < n; i++){
            if (hash[i] == 0){
                return i;
            }
        }
        return -1; */
          
        // optimal approach 1 --> summation approach
        int n = nums.size();
        // total sum
        int total_sum = (n*(n+1))/2;
        int sum = 0;
        for ( int i = 0; i < n; i++){
            sum+= nums[i];
        }
       return total_sum - sum; 


        // optimal approach 2 - XOR
       /* int xor1 = 0; // xor of all array elements
        int xor2 = 0; // xor of numbers from 1 to n
        int n = nums.size();
        for (int i = 0; i < n; i++){
            xor1 = xor1 ^ nums[i];
            xor2 = xor2 ^ (i+1);
        }
        xor2 = xor2 ^ n;
        return xor1 ^ xor2; */
    }
};