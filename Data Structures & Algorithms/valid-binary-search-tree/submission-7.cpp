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
    int mini;
    int maxi;
    bool isValid;

    Bst(int mini,int maxi,bool isValid)
    {
        this->mini=mini;
        this->maxi=maxi;
        this->isValid=isValid;
    }
 };

class Solution {
    Bst Solve(TreeNode* root)
    {
        //base case
        if(!root)
        {
            Bst bst=Bst(INT_MAX,INT_MIN,true);
            return bst;
        }
        if(root->left==NULL && root->right==NULL)
        {
            Bst bst=Bst(root->val,root->val,true);
            return bst;
        }

        auto leftPart=Solve(root->left);
        auto rightPart=Solve(root->right);

        if(leftPart.isValid && rightPart.isValid)
        {
            if(leftPart.maxi<root->val && root->val<rightPart.mini)
            {
                Bst bst=Bst(min(leftPart.mini,root->val),max(rightPart.maxi,root->val),true);
                return bst;
            }else
            {
                Bst bst=Bst(leftPart.mini,rightPart.maxi,false);
                return bst;
            }
        }else
        {
            Bst bst=Bst(leftPart.mini,rightPart.maxi,false);
            return bst;
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        Bst bst=Solve(root);
        return bst.isValid;
    }
};
