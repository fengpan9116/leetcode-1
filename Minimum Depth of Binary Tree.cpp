/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return callcnt ? INT_MAX : 0;
        if (!root->left && !root->right) return 1;
        callcnt = true;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
private:
    bool callcnt = false;
};