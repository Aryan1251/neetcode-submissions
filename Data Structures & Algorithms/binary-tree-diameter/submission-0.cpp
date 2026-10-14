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
    int D=0;
    int Solve(TreeNode* root)
    {
        if(!root) return 0;

        int op1=Solve(root->left);
        int op2=Solve(root->right);
        D=max(D,op1+op2);

        return 1+max(op2,op1);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        Solve(root);
        return D;
    }
};
