class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // [1, 2, 3]        [7, 4, 1]
        // [4, 5, 6]        [8, 5, 2]
        // [7, 8, 9]        [9, 6, 3]

        int r = matrix.size();
        int c = matrix[0].size();

        vector<vector<int>> res(c, vector<int> (r));

        for (int i = 0; i < r; i++){
            for (int j =  0; j < c; j++){
                res[j][i] = matrix[i][j];
            }
        }

        for ( int i = 0;i < r; i++){
            reverse( res[i].begin(), res[i].end());
        }

        for (int i = 0; i < c; i++){
            for (int j = 0; j < r; j++){
                matrix[i][j] = res[i][j];
            }
        }
    }
};