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
    bool ans=true;
    int Solve(TreeNode* root)
    {
        if(!root) return 0;

        int leftPart=Solve(root->left);
        int rightPart=Solve(root->right);

        if(abs(leftPart-rightPart)<=1)
        ans=ans&true;

        else ans=ans&false;

        return 1+max(leftPart,rightPart);
    }
public:
    bool isBalanced(TreeNode* root) {
        Solve(root);
        return ans;
    }
};
