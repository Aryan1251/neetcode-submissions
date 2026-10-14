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
    int ans=INT_MIN;
    int Solve(TreeNode* root)
    {
        if(!root) return 0;

        int lSum=Solve(root->left);
        int rSum=Solve(root->right);

        
        int op1=root->val+lSum+rSum;
        int op2=max(root->val+lSum,root->val+rSum);
        int op3=root->val;
        ans=max(ans,max(op1,max(op2,op3)));
        return max(op2,op3);
    }
public:
    int maxPathSum(TreeNode* root) {
        Solve(root);
        return ans;
    }
};
