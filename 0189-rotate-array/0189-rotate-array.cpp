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


        /* Brute force using extra space

        int n = nums.size();
        if (k == n) return;

        if (k > n){
            k = k % n; // to ensure it is within the range [0..n]
        }

        vector<int> ans(n);
        int j = 0;

        // aakhiri ke k elements pehle le aao
        for ( int i = n-k; i < n; i++){
            ans[j++] = nums[i];
        }

        // bache first elements iske baad
        for (int i = 0; i < n-k; i++){
            ans[j++] = nums[i];
        }

        // finally nums ko modify kardo
        for (int i = 0; i < n; i++){
            nums[i] = ans[i];
        }*/
    }
};