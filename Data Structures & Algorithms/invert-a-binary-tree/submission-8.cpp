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
    void Solve(TreeNode* root)
    {
        if(!root) return ;

        Solve(root->left);
        Solve(root->right);
        swap(root->left,root->right);

        return ;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        Solve(root);
        return root;
    }
};
