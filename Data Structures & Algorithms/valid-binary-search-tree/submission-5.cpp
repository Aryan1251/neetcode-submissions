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
class Bst{
    public:
    int maxi;
    int mini;
    bool isBst;

    Bst(int maxi,int mini,bool isBst)
    {
        this->maxi=maxi;
        this->mini=mini;
        this->isBst=isBst;
    }
};
class Solution {
    Bst Solve(TreeNode* root)
    {
        if(!root) return Bst(INT_MIN,INT_MAX,true);

        Bst leftPart=Solve(root->left);
        Bst rightPart=Solve(root->right);

        if(leftPart.maxi<root->val && root->val<rightPart.mini && leftPart.isBst && rightPart.isBst)
        {
            Bst bst=Bst(max(leftPart.maxi,max(rightPart.maxi,root->val)),min(rightPart.mini,min(leftPart.mini,root->val)),true);
            return bst;
        }else
        {
            Bst bst=Bst(root->val,root->val,false);
            return bst;
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        Bst ans=Solve(root);
        return ans.isBst;
    }
};
