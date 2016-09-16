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
        queue<ListNode*> shit;
        while(l1 || l2){
            if (l1 && (l2 && less(l1, l2) || !l2)){
                shit.push(l1);
                l1 = l1->next;
            }
            else{
                shit.push(l2);
                l2 = l2->next;
            }
        }
        auto res = shit.front();
        auto ret = res;
        shit.pop();
        while(!shit.empty()){
            res->next = shit.front();
            shit.pop();
            res = res->next;
        }
        res->next = NULL;
        return ret;
    }
};