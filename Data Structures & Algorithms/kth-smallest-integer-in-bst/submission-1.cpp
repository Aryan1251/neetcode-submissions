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
    int ans=-1;
    void Solve(TreeNode* root,int &k)
    {
        if(!root) return ;

        Solve(root->left,k);
        k--;
        if(k==0) ans=root->val;
        Solve(root->right,k);
        return ;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        Solve(root,k);
        return ans;
    }
};
