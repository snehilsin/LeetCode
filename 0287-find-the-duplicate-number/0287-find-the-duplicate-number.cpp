class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Array --> Linked List
        // Index --> represents node, value at that index --> next node

        // fast and slow pointers will meet if there is a cycle in the linked list 
        // indicating a duplicate number

        int slow = nums[0];
        int fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while ( slow != fast);

        slow = nums[0];
        while (slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;


        

    }
};