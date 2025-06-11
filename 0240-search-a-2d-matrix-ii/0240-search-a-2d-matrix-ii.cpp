class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // i can start traversing either from (0, m-1) or (n-1, 0)

        // (0, m-1)
        // 1 4 7 11 15    col wise --> increasing order
        // 2 5 8 12 19    row wise --> decreasing order
        // 3 6 9 16 22
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0;
        int col = m-1;

        while (row < n && col >= 0){
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target){
                // i want a greater number
                // i would want to move col wise
                // that is shift by one row 
                row++;
            } else {
                col--;
            }
        }
        return false;
        
    }
};