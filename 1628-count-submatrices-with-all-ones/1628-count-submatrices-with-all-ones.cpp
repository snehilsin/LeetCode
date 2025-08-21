class Solution {
public:

    int helper(vector<vector<int>> &mat, int a , int b){
        // submatrices with top-left corner at mat[a][b]

        int m = mat.size();
        int n = mat[0].size();
        int count = 0;
        int bound = n;
        for (int i = a; i < m; i++){
            for(int j = b; j < bound; j++){
                if (mat[i][j]){
                    count += 1;
                } else {
                    bound = j;
                }
            }
        }
        return count;
    }
    int numSubmat(vector<vector<int>>& mat) {
        // bound --> to shrink the search space because if we hit a zero, then there is no point in iterating past that point
        int m = mat.size();
        int n = mat[0].size();

        int count = 0;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                count += helper(mat, i, j);
            }
        }
        return count;
    }
};