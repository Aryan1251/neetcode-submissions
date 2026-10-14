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

        int leftPart=Solve(root->left);
        int rightPart=Solve(root->right);
        D=max(D,leftPart+rightPart+1);

        return 1+max(leftPart,rightPart);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        Solve(root);
        return D-1;
    }
};
