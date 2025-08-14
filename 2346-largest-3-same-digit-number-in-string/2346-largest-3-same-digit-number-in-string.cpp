class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string ans = "";
        for ( int i = 0; i <= n-3; i++){
            if ( num[i] == num[i+1] && num[i] == num[i+2]){
                string triplet = num.substr(i, 3);
                if ( triplet > ans){
                    ans = triplet;
                }
            }
        }
        return ans;
    }
};