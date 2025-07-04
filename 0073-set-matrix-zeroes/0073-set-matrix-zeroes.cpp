class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // see previous one
      /*  int n =  matrix.size();
        int m = matrix[0].size();
        vector<bool> rows(n, false);
        vector<bool> cols(m, false);

        for ( int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (matrix[i][j] == 0){
                    rows[i]=  true;
                    cols[j] = true;
                }
            }
        }

        for ( int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (rows[i] || cols[j]){
                    matrix[i][j] = 0;
                }
            }
        } */

        int n = matrix.size();
        int m = matrix[0].size();
        int c0 = 1;
        for ( int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if (matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    if (j == 0){
                        c0 = 0;
                    } else {
                        matrix[0][j] = 0;
                    }
                }
            }
        }

        for (int i = 1; i < n; i++){
            for (int j = 1; j < m; j++){
                if (matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if (matrix[0][0] == 0){
            for (int j = 0; j < m; j++){
                matrix[0][j] = 0;
            }
        }
        if (c0 == 0){
            for (int i = 0; i < n; i++){
                matrix[i][0] = 0;
            }
        }
    }
};