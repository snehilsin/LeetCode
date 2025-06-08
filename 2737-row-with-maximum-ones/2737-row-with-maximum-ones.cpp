class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int cnt_max = 0;
        int index = 0;
        for (int i = 0; i < mat.size(); i++){
            int cnt_ones = 0;
            for (int j = 0; j < mat[0].size(); j++){
                if (mat[i][j] == 1){
                    cnt_ones++;
                }
            }

            if (cnt_ones > cnt_max){
                cnt_max = cnt_ones;
                index = i;
            }
        }
        return {index, cnt_max};
    }
};