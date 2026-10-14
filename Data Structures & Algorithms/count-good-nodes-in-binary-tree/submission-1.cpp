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
    void Solve(TreeNode* root,int maxNode,int &cnt)
    {
        if(!root) return ;

        if(root->val>=maxNode) cnt++;

        Solve(root->left,max(maxNode,root->val),cnt);
        Solve(root->right,max(maxNode,root->val),cnt);

        return ;
    }
public:
    int goodNodes(TreeNode* root) {
        int cnt=0;
        Solve(root,-101,cnt);
        return cnt;
    }
};
