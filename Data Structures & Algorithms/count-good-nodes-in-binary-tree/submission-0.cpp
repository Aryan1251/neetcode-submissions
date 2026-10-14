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
    private:
    void Solve(TreeNode* root,int maxi,int &cnt)
    {
        if(root==NULL) return ;
        

        Solve(root->left,max(root->val,maxi),cnt);
        if(root->val>=maxi) cnt++;
        Solve(root->right,max(root->val,maxi),cnt);
    }
public:
    int goodNodes(TreeNode* root) {
        int cnt=0;
        int maxi=INT_MIN;
        Solve(root,maxi,cnt);
        return cnt;
    }
};
