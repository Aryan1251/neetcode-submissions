/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    TreeNode* Solve(TreeNode* root)
    {
        if(!root) return nullptr;

        TreeNode* node=new TreeNode(root->val);
        node->left=Solve(root->right);
        node->right=Solve(root->left);

        return node;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        root=Solve(root);
        return root;
    }
};
