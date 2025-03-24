/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
   /* int findLen (ListNode* head){
        int cnt = 0;
        ListNode* temp = head;
        while (temp != NULL){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    } 
    ListNode* middleNode(ListNode* head) {
        // brute force approach
        int len = findLen(head);
        int mid = len/2 + 1;
        ListNode* temp = head;
        while (mid){
            mid = mid -1;
            if (mid == 0){
                break;
            }
            temp = temp->next;
        }
        return temp;
    } 
    */

    ListNode* middleNode(ListNode* head){
         if (head == NULL || head->next == NULL){
            return head;
         }
         ListNode* slow = head;
         ListNode* fast = head;
         while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
         }
         return slow;
    }
};