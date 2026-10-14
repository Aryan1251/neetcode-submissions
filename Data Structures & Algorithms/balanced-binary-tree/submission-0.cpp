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
    private:
    bool ans=true;
    int h=0;
    int Solve(TreeNode* root)
    {
        if(!root) return 0;

        int lh=Solve(root->left);
        int rh=Solve(root->right);

        if(abs(lh-rh)<=1)
        ans=ans & true;
        else
        ans=ans & false;

        return 1+max(lh,rh);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        Solve(root);
        return ans;
    }
};
