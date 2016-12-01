/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        auto parent = root;
        auto leftiest = root->left;
        while (parent) {
            if (parent->left) parent->left->next = parent->right;
            if (parent->right && parent->next)
                parent->right->next = parent->next->left;
            if (!parent->next){
                parent = leftiest;
                if (leftiest) leftiest = leftiest->left ? leftiest->left : leftiest->right;
            }
            else parent = parent->next;
        }
    }
};