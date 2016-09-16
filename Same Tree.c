/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) return true;
    else if (p == NULL || q == NULL) return false;
    bool lflag = false;
    bool rflag = false;
    if (p->val == q->val){
        lflag = isSameTree(p->left, q->left);
        rflag = isSameTree(p->right, q->right);
    }
    else return false;
    return lflag && rflag;
}