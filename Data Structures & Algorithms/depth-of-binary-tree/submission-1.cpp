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
    int Solve(TreeNode* root)
    {
        if(!root) return 0;

        int lh=Solve(root->left);
        int rh=Solve(root->right);

        return 1+max(lh,rh);
    }
public:
    int maxDepth(TreeNode* root) {
        int ans=Solve(root);
        return ans;
    }
};
