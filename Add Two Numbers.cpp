/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum, l1v, l2v;
        ListNode* res = new ListNode(0);
        auto lolhead = res;
        while (l1 || l2 || carry) {
            l1v = l1 ? l1->val : 0;
            l2v = l2 ? l2->val : 0;
            sum = l2v + l1v + carry;
            if (sum > 9) {
                carry = 1;
                sum -= 10;
            } else carry = 0;
            ListNode* next = new ListNode(sum);
            res->next = next;
            res = next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return lolhead->next;
    }
};