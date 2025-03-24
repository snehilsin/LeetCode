class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Brute force approach
        // use two  arrays --> row and col
        // row and col will contain those indices which must be marked as 0

      /*  int n = matrix.size();
        int m = matrix[0].size();
        vector<bool> rows(n, false);
        vector<bool> cols(m, false);


        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (matrix[i][j] == 0){
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (rows[i] || cols[j]){
                    matrix[i][j] = 0;
                }
            }
        } */

        // space optimized approach

        // instead of using two extra matrices row and col, we will use the 1st row and 1st column of the given matrix to keep a track of the cells that need to be marked with 0. But here comes a problem. If we try to use the 1st row and 1st column to serve the purpose, the cell matrix[0][0] is taken twice. To solve this problem we will take an extra variable col0 initialized with 1. Now the entire 1st row of the matrix will serve the purpose of the row array. And the 1st column from (0,1) to (0,m-1) with the col0 variable will serve the purpose of the col array.

        int n = matrix.size();
        int m = matrix[0].size();
        int c0 = 1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (matrix[i][j] == 0){
                    matrix[i][0] = 0;   // mark ith row
                    if (j == 0){
                        c0 = 0; // 0th col
                    } else {
                        matrix[0][j] = 0; // else jth col
                    }
                }
            }
        }

        // mark from (1, 1) to (n-1, m-1)
        for (int i = 1; i < n; i++){
            for (int j = 1; j < m; j++){
                if (matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        // then mark the first row if need to
        if (matrix[0][0] == 0){
            for (int j = 0; j < m; j++){
                matrix[0][j] = 0;
            }
        }
        // mark the first col if need to
        if (c0 == 0){
            for (int i = 0; i < n; i++){
                matrix[i][0] = 0;
            }
        }
    }
};