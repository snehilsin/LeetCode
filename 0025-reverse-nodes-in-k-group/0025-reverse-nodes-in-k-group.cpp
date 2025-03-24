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

    ListNode* reverse(ListNode* head, int k){
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (k > 0 && curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            k--;
        }
        head->next = curr;
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // recursion
        // recursively, reverse groups of k everytime if possible


        // 1. first check if k nodes exist
        // 2. Recursively, reverse the rest of the linked list 
        // 3. Reverse the current group

        // first node of the linked list ko bache hue  ll ke saath connect karna hoga
        // 1->2->3->4->5 , k = 2
        // 2->1 , 4->3->5  (isko rev karne ke baad)

        // 2->1 ----> 4->3->5  (first node -> bacha hua ll)


      

        if (head == NULL || k <= 1){
            return head;
        }
        int cnt = 0;
        ListNode* temp = head;
        while (temp){
            cnt++;
            temp = temp->next;
        }
        int groups = cnt / k;
        ListNode* newHead = NULL;
        ListNode* prevTail = NULL;
        ListNode* curr = head;

        while (groups > 0){
            ListNode* groupHead = reverse(curr, k); // rev 1st group

            if (newHead == NULL){
                newHead = groupHead;
            } else {
                prevTail->next = groupHead;  // prev group ke tail ka next --> next group ka head
            }
            prevTail = curr;
            curr = curr->next;
            groups--;

        }
        return newHead;

    }
};