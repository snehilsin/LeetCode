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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* evenHead = new ListNode(0);
        ListNode* oddHead = new ListNode(0);
        ListNode* oddTail = oddHead;
        ListNode* evenTail = evenHead;
        ListNode* curr = head;
        int index = 1;
        while (curr != NULL){
            if (index % 2 == 1){
                oddTail->next = curr;
                oddTail = oddTail->next;
            } else{
                evenTail->next = curr;
                evenTail = evenTail->next;
            }
            curr = curr->next;
            index++;
        }
        oddTail->next = evenHead->next;
        evenTail->next = NULL;
        ListNode* res = oddHead->next;
        delete oddHead;
        delete evenHead;
        return res;
    }
};