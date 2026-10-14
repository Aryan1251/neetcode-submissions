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
    TreeNode* Solve(vector<int>& preorder,vector<int>& inorder,unordered_map<int,int>& mp,int& preIndex,int st,int end)
    {
        if(st>end) return NULL;

        int index=mp[preorder[preIndex]];
        TreeNode* root=new TreeNode(preorder[preIndex]);
        preIndex+=1;
        root->left=Solve(preorder,inorder,mp,preIndex,st,index-1);
        root->right=Solve(preorder,inorder,mp,preIndex,index+1,end);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex=0;
        int st=0,end=inorder.size()-1;
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        TreeNode* root=Solve(preorder,inorder,mp,preIndex,st,end);
        return root;
    }
};
