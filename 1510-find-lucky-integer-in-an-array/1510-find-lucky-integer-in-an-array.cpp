class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mpp;
        for (int x : arr){
            mpp[x]++;
        }
        int maxAns = -1;
        for (auto it : mpp){
            if (it.first == it.second){
               int  ans = it.first;
               maxAns =max(maxAns, ans); 
            }
            
        }
        return maxAns;
    }
};