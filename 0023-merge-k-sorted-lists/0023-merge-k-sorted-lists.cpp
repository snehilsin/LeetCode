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
   ListNode* merge (ListNode* l1, ListNode* l2){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;
        while (l1 != NULL && l2 != NULL){
            if (l1->val <= l2->val){
                curr->next = l1;
                l1 = l1->next;
            } else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if (l1 != NULL){
            curr->next = l1;
        }
        if (l2 != NULL){
            curr->next = l2;
        }
        return dummyNode->next;
   }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()){
            return NULL;
        }

        while (lists.size() > 1){
            vector<ListNode*> temp;
            for (int i = 0; i < lists.size(); i+=2){
                ListNode* l1 = lists[i];
                ListNode* l2 = i + 1 < lists.size() ? lists[i+1] : NULL;
                temp.push_back(merge(l1, l2));
            }
            lists = temp;
        }
        return lists[0];
    }
};