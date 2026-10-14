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
    int leftMax;
    int rightMin;
    bool isValid;

    Bst()
    {
        this->leftMax=INT_MIN;
        this->rightMin=INT_MAX;
        this->isValid=true;
    }
};
class Solution {
    Bst Solve(TreeNode* root)
    {
        if(!root)
        {
            Bst bst=Bst();
            return bst;
        }
        if(root->left==NULL && root->right==NULL)
        {
            Bst bst=Bst();
            bst.leftMax=root->val;
            bst.rightMin=root->val;
            bst.isValid=true;
            return bst;
        }

        auto leftPart=Solve(root->left);
        auto rightPart=Solve(root->right);

        if(leftPart.isValid && rightPart.isValid)
        {
            if(root->val>leftPart.leftMax && root->val<rightPart.rightMin)
            {
                auto bst=Bst();
                bst.leftMax=max(max(leftPart.leftMax,rightPart.leftMax),root->val);
                bst.rightMin=min(min(leftPart.rightMin,rightPart.rightMin),root->val);
                bst.isValid=true;
                return bst;
            }
            else
            {
                Bst bst=Bst();
                bst.leftMax=INT_MIN;
                bst.rightMin=INT_MAX;
                bst.isValid=false;
                return bst;
            }
        }else
        {
            Bst bst=Bst();
            bst.leftMax=INT_MIN;
            bst.rightMin=INT_MAX;
            bst.isValid=false;
            return bst;
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        auto bst=Solve(root);
        return bst.isValid;
    }
};
