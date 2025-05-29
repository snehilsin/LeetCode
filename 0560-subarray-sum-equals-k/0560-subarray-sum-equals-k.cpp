class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // map --> index, cnt of such subarrays
        unordered_map<int, int> mp;
        int sum = 0;
        int ans = 0;
        mp[sum] = 1; // to handle the case when the starting element i.e. element at index 0 has sum k
        for (auto it : nums){
            sum += it;
            int find = sum - k;
            if (mp.find(find) != mp.end()){
                ans += mp[find];
            }
            mp[sum]++;
        }
        return ans;
    }
};