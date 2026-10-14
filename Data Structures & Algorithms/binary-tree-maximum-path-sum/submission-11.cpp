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

        int leftPart=Solve(root->left);
        int rightPart=Solve(root->right);

        int op1=leftPart+root->val;
        int op2=rightPart+root->val;
        int op3=leftPart+rightPart+root->val;

        maxSum=max(max(maxSum,root->val),max(op1,max(op2,op3)));

        return max(op1,max(op2,root->val));
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root->left==NULL && root->right==NULL) return root->val;
        Solve(root);
        return maxSum;
    }
};
