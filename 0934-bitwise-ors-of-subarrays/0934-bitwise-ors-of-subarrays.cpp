class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res, curr, next;
        for (int num : arr){
            next.clear();
            next.insert(num);
            for ( int x : curr){
                next.insert(x|num);
            }
            curr = next;
            res.insert(curr.begin(), curr.end());
        }
        return res.size();
    }
};