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

        int lh=Solve(root->left);
        int rh=Solve(root->right);

        int currD=lh+rh+1;
        D=max(currD,D);

        return max(lh,rh)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        Solve(root);
        return D-1;
    }
};
