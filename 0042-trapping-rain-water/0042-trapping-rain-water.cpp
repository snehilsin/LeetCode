class Solution {
public:
    int trap(vector<int>& height) {
      /*  int n = height.size();
        int res = 0;
        for (int i = 0; i < n; i++){
            int left = height[i];

            for (int j = 0; j < i; j++){
                left = max(left, height[j]);
            }

            int right = height[i];

            for (int j = i + 1; j < n; j++){
                right = max(right, height[j]);
            }
            res += min(left, right) - height[i];
        }
        return res; */

        // better --> precompute
       /* int n = height.size(); 
        vector<int> left(n);
        vector<int> right(n);
        int res = 0;
        left[0] = height[0];
        for (int i = 1; i < n; i++){
            left[i] = max(left[i-1], height[i]);
        }
        right[n-1] = height[n-1];
        for ( int i = n-2; i >= 0; i--){
            right[i] = max(right[i+1], height[i]);
        }

        for (int i = 1; i < n-1; i++){
            int minOf2 = min(left[i-1], right[i-1]);
            if (minOf2 > height[i]){
                res += minOf2  - height[i];
            }
        }
        return res; */
        int n = height.size();
        int left = 0;
        int right =  n-1;
        int maxLeft = 0;
        int maxRight = 0;
        int res = 0;
        while (left <= right){
            if (height[left] <= height[right]){
                if (height[left] >= maxLeft){
                    maxLeft = height[left];
                } else {
                    res += maxLeft - height[left];
                }
                left++;
            }  else {
                if (height[right] >= maxRight){
                    maxRight = height[right];
                } else {
                    res += maxRight - height[right];
                }
                right--;
            }
        }
        return res;
    }
};