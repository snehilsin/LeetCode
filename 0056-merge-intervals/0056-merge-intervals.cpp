class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        ans.push_back(intervals[0]);

        for (int i = 1; i < n; i++){
            vector<int> &last = ans.back();
            vector<int> &curr = intervals[i];

            if (curr[0] <= last[1] ){
                last[1] = max(last[1], curr[1]);
            } else {
                ans.push_back(curr);
            }
        }
        return ans;
    }
};