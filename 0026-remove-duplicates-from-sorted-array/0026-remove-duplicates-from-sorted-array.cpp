class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0; // ye pointer help karega unique elements store karne mein
        // toh iss pointer ki help se in place modification karte hai

        int n = nums.size();

        for ( int j = 1; j < n; j++){
            if (nums[i] != nums[j]){
                i++;
                nums[i] = nums[j]; // unique hai toh store karlo na
            }
        }
        return i + 1; // obviously kyunki tumne 0-based indexing jo ki, toh return i+1 (unique number of elements)
    }
};