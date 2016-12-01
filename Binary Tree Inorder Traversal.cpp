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
    vector<int> inorderTraversal(TreeNode* root) {
        curse(root);
        return res;
    }
private:
    vector<int> res;
    void curse(TreeNode* node) {
        if (!node) return;
        curse(node->left);
        res.emplace_back(node->val);
        curse(node->right);
    }
};