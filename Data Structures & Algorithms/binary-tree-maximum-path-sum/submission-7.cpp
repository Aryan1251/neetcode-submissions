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

        int leftPart=Solve(root->left);
        int rightPart=Solve(root->right);

        int op1=leftPart+root->val;
        int op2=rightPart+root->val;
        int op3=leftPart+rightPart+root->val;
        int op4=root->val;

        ans=max(ans,max(max(op1,op2),max(op3,op4)));

        return max(op1,max(op2,op4));
    }
public:
    int maxPathSum(TreeNode* root) {
        int Ans=Solve(root);
        ans=max(ans,Ans);
        return ans==INT_MIN?0:ans;
    }
};
