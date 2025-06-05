class Solution {
public:
    bool isSafe(int n, vector<string> &nQueens, int row, int col){
        // if same column
        for (int i = 0; i < n; i++){
            if (nQueens[i][col] == 'Q'){
                return false;
            }
        }

        // upper left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i-- , j--){
            if (nQueens[i][j] == 'Q'){
                return false;
            }
        }

        // upper right
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
            if (nQueens[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void helper(int n, vector<vector<string>> &ans, vector<string> &nQueens, int row){
        if (row == n){
            ans.push_back(nQueens);
            return;
        }

        // try placing in each col of curr row
        for (int col = 0; col < n; col++){
            if (isSafe(n, nQueens, row, col)){
                nQueens[row][col] = 'Q';
                helper(n, ans, nQueens, row + 1);
                nQueens[row][col] = '.'; // backtrack, try for next pos
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> nQueens(n, string(n, '.'));
        helper(n, ans, nQueens, 0); // start solving from row 0
        return ans;
    }
};