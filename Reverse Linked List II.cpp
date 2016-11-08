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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        auto cur = head, before = head;
        stack<ListNode*> fuckers;
        // Manually advance the list
        for (int i = 0; i < n; i++){
            if (i >= m-1)
                fuckers.emplace(cur);
            else before = cur;
            cur = cur->next;
        }
        auto after = cur;
        auto top = fuckers.empty() ? after : fuckers.top();
        if (m > 1) before->next = top;
        else head = top;
        if (!fuckers.empty()) fuckers.pop();
        cur = top;
        while (!fuckers.empty()){
            cur->next = fuckers.top();
            cur = cur->next;
            fuckers.pop();
        }
        cur->next = after;
        return head;
    }
};