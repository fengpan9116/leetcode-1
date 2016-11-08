/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> old_to_new;
        old_to_new[nullptr] = nullptr;
        RandomListNode *new_head = nullptr, *cur = head;
        while(cur){
            auto newcur = new RandomListNode(cur->label);
            newcur->next = cur->next;
            newcur->random = cur->random;
            old_to_new[cur] = newcur;
            cur = cur->next;
            newcur->next = cur;
            if (!new_head) new_head = newcur;
        }
        // Translate pointers
        cur = new_head;
        while(cur){
            cur->random = old_to_new[cur->random];
            cur->next = old_to_new[cur->next];
            cur = cur->next;
        }
        return new_head;
    }
};