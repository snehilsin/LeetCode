class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // take transpose and then reverse each row
        int cols = matrix[0].size();
        int rows = matrix.size();
        vector<vector<int>> res(cols, vector<int> (rows));

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                res[j][i] = matrix[i][j];
            }
        }
        for (int i = 0; i <  rows; i++){
            reverse(res[i].begin(), res[i].end());
        }
        for (int i = 0; i < cols; i++){
            for (int j = 0; j < rows; j++){
                matrix[i][j] = res[i][j];
            }
        }
    }
};