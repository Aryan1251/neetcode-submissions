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
    int cnt=0;
    void Solve(TreeNode* root,int maxNode)
    {
        if(!root) return ;

        maxNode=max(maxNode,root->val);
        if(root->val>=maxNode) cnt++;
        Solve(root->left,maxNode);
        Solve(root->right,maxNode);

        return ;
    }
public:
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        if(root->left==nullptr && root->right==nullptr) return 1;
        int maxNode=INT_MIN;
        Solve(root,maxNode);
        return cnt;
    }
};
