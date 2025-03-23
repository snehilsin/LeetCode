class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Brute force approach using extra space

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
        }
    }
};