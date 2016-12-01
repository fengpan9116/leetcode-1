/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
bool cmp (ListNode* a, ListNode* b){
    return a->val < b->val;
}
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr;
        auto cur = head->next;
        vector<ListNode*> v;
        v.emplace_back(head);
        while (cur){
            v.emplace_back(cur);
            cur = cur->next;
        }
        sort(v.begin(), v.end(), cmp);
        for (size_t i = 0; i < v.size()-1; i++){
            v[i]->next = v[i+1];
        }
        v.back()->next = nullptr;
        return v.front();
    }
};