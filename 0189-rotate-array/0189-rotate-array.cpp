class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Brute force

        /*int n = nums.size();
        if (k > n){
            k = k % n;
        }

        vector<int> ans(n);
        int j = 0;

        // aakhri ke k elements pehle le aao
        for (int i = n-k; i < n; i++){
            ans[j++] = nums[i];
        }

        // bache first elements iske baad
        for(int i = 0; i < n; i++){
            ans[j++] = nums[i];
        }

        // finally nums ko modify kardo
        for(int i = 0; i < n; i++){
            nums[i] = ans[i];
        } */

        // reversal algo

        int n = nums.size();
        if (k == n) return;
        if ( k > n){
            k = k % n;
        }

        // reverse the last k elements
        reverse(nums.begin() + (n-k), nums.end());

        // reverse the first rem elements
        reverse(nums.begin(), nums.begin() + (n-k));

        // now reverse the whole array
        reverse(nums.begin(), nums.end());
    }
};