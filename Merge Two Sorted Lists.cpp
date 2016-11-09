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
    bool less(ListNode* l1, ListNode* l2){return l1->val < l2->val;}
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return NULL;
        if (!l1 || !l2) return l1? l1 : l2;
        queue<ListNode*> q;
        while(l1 || l2){
            if (l1 && (l2 && less(l1, l2) || !l2)){
                q.push(l1);
                l1 = l1->next;
            }
            else{
                q.push(l2);
                l2 = l2->next;
            }
        }
        auto res = q.front();
        auto ret = res;
        q.pop();
        while(!q.empty()){
            res->next = q.front();
            q.pop();
            res = res->next;
        }
        res->next = NULL;
        return ret;
    }
};