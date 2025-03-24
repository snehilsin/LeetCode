class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int cnt_max = 0;
        int index = 0;

        // iterate over the rows
        for (int i = 0; i < mat.size(); i++){
            int cnt_ones = 0;
            // find the cnt of 1s in the current row
            for (int j = 0; j < mat[0].size(); j++){
                if (mat[i][j] == 1){
                    cnt_ones++;
                }
            }

            // update the cnt of max 1s
            if (cnt_ones > cnt_max){
                cnt_max = cnt_ones;
                index = i;
            }
        }
        return {index, cnt_max};
    }
};