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
 class Tree{
    public:
    bool isBst;
    int maxi;
    int mini;

    Tree(bool isBst,int maxi,int mini)
    {
        this->isBst=isBst;
        this->maxi=maxi;
        this->mini=mini;
    }
 };

class Solution {
    Tree* isValid(TreeNode* root)
    {
        if(!root)
        {
            Tree* tree=new Tree(true,INT_MIN,INT_MAX);
            return tree;
        }
        if(root->left==NULL && root->right==NULL)
        {
            Tree* tree=new Tree(true,root->val,root->val);
            return tree;
        }

        auto leftPart=isValid(root->left);
        auto rightPart=isValid(root->right);

        if(!leftPart->isBst || !rightPart->isBst)
        {
            Tree* tree=new Tree(false,INT_MAX,INT_MIN);
            return tree;
        }
        else if(root->val>leftPart->maxi && root->val<rightPart->mini)
        {
            int leftMax=max(leftPart->maxi,rightPart->maxi);
            int rightMin=min(leftPart->mini,rightPart->mini);
            leftMax=max(leftMax,root->val);
            rightMin=min(rightMin,root->val);
            Tree* tree=new Tree(true,leftMax,rightMin);
            return tree;
        }
        else
        {
            Tree* tree=new Tree(false,INT_MAX,INT_MIN);
            return tree;
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        Tree* tree=isValid(root);
        return tree->isBst;
    }
};
