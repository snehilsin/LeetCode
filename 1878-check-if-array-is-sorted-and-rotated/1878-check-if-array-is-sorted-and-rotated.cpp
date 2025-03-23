class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i-1] > nums[i]){
                cnt++;
            }
        }
        if (nums[nums.size()-1] > nums[0]){
            cnt++;
        }
        return cnt <= 1; // cnt toh ek se chota ya equal hi hona chahiye tabhi sorted + rotated
        // agar ek se bada hai toh obviously no way vo sorted hoga, aur usse rotate karne ke baad bhi sorted nhi milne wala
    }
};