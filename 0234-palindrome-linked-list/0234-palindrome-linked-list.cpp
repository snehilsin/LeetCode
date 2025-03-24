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
    ListNode* reverse(ListNode* head){
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;

    }
    bool isPalindrome(ListNode* head) {
        // brute force approach
        // using stack
      /*  stack<ListNode*> st;
        ListNode* temp = head;
        while (temp != NULL){
            st.push(temp);
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL){
            if (temp->val != st.top()->val){
                return false;
            }
            st.pop();
            temp = temp->next;
        }
        return true; */

        // reversing only the first half
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = reverse(slow->next);
        ListNode* first = head;
        ListNode* second = newHead;
        while (second != NULL){
            if (first->val != second->val){
                reverse(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverse(newHead);
        return true;
    }
};