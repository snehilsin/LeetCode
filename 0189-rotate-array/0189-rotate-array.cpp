class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // reversal algo

        int n = nums.size();
        if (k > n){
            k = k % n;
        }
        // aakhiri ke elements reverse kar
        reverse(nums.begin() + (n-k), nums.end());

        // bache hue first elements bhi reverse kar
        reverse(nums.begin(), nums.begin() + n - k);

        // kuch mil gya na ab
        // pura reverse kar
        reverse(nums.begin(), nums.end());

        // [1, 2, 6, 7, 8, 3] , k = 3
        // aakhiri ke k elements reverse
        // [1, 2, 6, 3, 8, 7]
        // bache hue first elements reverse
        // [6, 2, 1, 3, 8, 7]
        // pura reverse
        // [7, 8, 3, 1, 2, 6]
    }
};