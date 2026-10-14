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
    int maxSum=INT_MIN;
    int Solve(TreeNode* root)
    {
        if(!root) return 0;

        int leftSum=Solve(root->left);
        int rightSum=Solve(root->right);

        int op1=leftSum+root->val;
        int op2=rightSum+root->val;
        int op3=leftSum+rightSum+root->val;

        maxSum=max(maxSum,max(max(op1,op2),max(op3,root->val)));

        int ans= max(root->val,max(op2,op1));
        return ans;
    }
public:
    int maxPathSum(TreeNode* root) {
        int sum=Solve(root);
        return maxSum;
    }
};
