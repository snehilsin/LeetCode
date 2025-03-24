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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2 ) {
        // 1->2->3
        // 4->5->6

        // 1->2->3->4->5->6
        //  n = 4
        // 4

        // 1->2->3
        // 4->5->6

        // res --> pointing to my res list
        // temp --> to traverse l1 and l2
        ListNode* res = new ListNode(-1);
        ListNode* temp = res;
        while (list1 != NULL && list2 != NULL){
            if (list1->val <= list2->val){
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if (list1 != NULL){
            temp->next = list1;
        }
        if (list2 != NULL){
            temp->next = list2;
        }
        return res->next;
    }
};