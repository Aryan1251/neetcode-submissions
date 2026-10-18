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
#define ll long long

class Solution {
    ll maxSum=INT_MIN;
    ll Solve(TreeNode* root)
    {
        if(!root) return INT_MIN;

        ll leftPart=Solve(root->left);
        ll rightPart=Solve(root->right);

        ll op1=leftPart+root->val+rightPart;
        ll op2=leftPart+root->val;
        ll op3=rightPart+root->val;

        maxSum=max(maxSum,max(op1,max(op2,max(op3,max(leftPart,max(rightPart,(ll)root->val))))));

        ll returnSum=max(op2,max(op3,(ll)root->val));
        return returnSum;
    }
public:
    int maxPathSum(TreeNode* root) {
        Solve(root);
        return (int)maxSum;
    }
};
