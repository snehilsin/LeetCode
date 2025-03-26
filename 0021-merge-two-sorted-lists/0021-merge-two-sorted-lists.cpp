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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;
        while (list1 != NULL && list2 != NULL){
            if (list1->val <= list2->val){
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        if(list1 != NULL){
            // no need of looping simply attach it
            curr->next = list1;
        
            
        }
       if(list2 != NULL){
            curr->next = list2;
          
        }
        return dummyNode->next;
    }

    // [1, 2, 4], [1, 3, 4]
    // [-1]-> 1-> 1->2->3->4->4
    //  curr
    // [1, 2, 3, 4, 5, 6], [2, 3]
    // [-1] -> 1->2->3->3->4
};