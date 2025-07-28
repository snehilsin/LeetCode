class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // create a min heap of size k every time
        // s.t it contains k largest elements every time
        // for that i will compare the curr elementt of the array with pq top
        // if curr element < pq.top() --> no use
        // if curr element > pq.top() --> then pop top ans insert curr in pq
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k; i++){
            pq.push(nums[i]);
        }

        for (int i = k; i < nums.size(); i++){
            if (nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};