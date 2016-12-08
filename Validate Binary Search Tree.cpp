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
    bool isValidBST(TreeNode* root) {
        return isValidBullshit(root, LONG_MIN, LONG_MAX);
    }
    bool isValidBullshit(TreeNode* root, long gmin, long gmax) {
        if (!root) return true;
        if (root->val <= gmin || root->val >= gmax) return false;
        return isValidBullshit(root->left, gmin, root->val) && 
            isValidBullshit(root->right, root->val, gmax);
    }
};