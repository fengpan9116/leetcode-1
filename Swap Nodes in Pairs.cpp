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
    ListNode* swapPairs(ListNode* head) {
        if (!head) return nullptr;
        vector<ListNode*> nodes;
        while(head){
            nodes.emplace_back(head);
            head = head->next;
        }
        for (int i = 1; i < nodes.size(); i += 2)
            swap(nodes[i], nodes[i-1]);
        for (int i = 0; i < nodes.size(); i++)
            nodes[i]->next = i < nodes.size()-1 ? nodes[i+1] : nullptr;
        return nodes[0];
    }
};