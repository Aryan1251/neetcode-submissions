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
    void Solve(TreeNode* root,int maxi,int& cnt)
    {
        if(!root) return ;

        if(root->val>=maxi) cnt++;
        maxi=max(maxi,root->val);

        Solve(root->left,maxi,cnt);
        Solve(root->right,maxi,cnt);
    }
public:
    int goodNodes(TreeNode* root) {
        if(root->left==NULL && root->right==NULL) return 1;
        int maxi=root->val;
        int cnt=0;
        Solve(root,maxi,cnt);
        return cnt;
    }
};
