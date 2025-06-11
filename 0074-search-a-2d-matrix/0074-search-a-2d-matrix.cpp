class Solution {
public:
    
   /* bool binarySearch(vector<int> &nums, int target){
        int low = 0;
        int high = nums.size()-1;
        while (low <= high){
            int mid = low + (high - low)/2;
            if (nums[mid] == target) return true;
            else if (nums[mid] < target) low = mid + 1;
            else high = mid -1;
        }
        return false;
    } */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       /* int n = matrix.size();
        int m = matrix[0].size();
       for (int i = 0; i < n; i++){
        if (matrix[i][0] <= target && target <= matrix[i][m-1]){
            return binarySearch(matrix[i], target);
        }
       }
       return false; */
       // formula
       // imaginary conversion of 2d matrix to 1d array
       // row = i/m, col = i % m
       int n = matrix.size();
       int m = matrix[0].size();
       int low = 0;
       int high = n*m -1;
       while (low <= high){
        int mid = low + (high - low)/2;
        int row = mid/m;
        int col = mid % m;
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) low = mid + 1;
        else high = mid -1;
       }
       return false;
    }
};