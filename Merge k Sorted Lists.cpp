/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
bool cmp(ListNode* l1, ListNode* l2){
    return l1->val < l2->val;
}
void binarySwap(vector<ListNode*>& lists){
    size_t start = 0, end = lists.size(), mid = (end-start)/2;
    if (lists[0] < )
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Check for jokers
        volatile size_t size = lists.size();
        for (size_t i = 0; i < size; ){
            if (lists[i] == NULL){
                lists.erase(lists.begin()+i);
                i = 0;
                size = lists.size();
            }
            else i++;
        }
        ListNode *cur = NULL, *head = NULL;
        while(lists.size()){
            if (!lists[0]){
                lists.erase(lists.begin());
                if (!lists.size()) break;
            }
            sort(lists.begin(), lists.end(), cmp);
            if (cur) cur->next = lists.front();
            cur = lists.front();
            if (!head) head = cur;
            lists[0] = lists[0]->next;
        }
        if (cur) cur->next = NULL;
        return head;
    }
};