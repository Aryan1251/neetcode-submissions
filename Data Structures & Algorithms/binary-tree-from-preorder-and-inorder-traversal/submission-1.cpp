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
    int findInorderIndex(vector<int>& inorder,int st,int end,int val)
    {
        for(int i=st;i<=end;i++)
        {
            if(inorder[i]==val) return i;
        }
        return -1;
    }
    TreeNode* Solve(vector<int>& preorder,vector<int>& inorder,int &preIndex,int st,int end)
    {
        if(preIndex>=preorder.size() || st>end) return nullptr;

        int index=findInorderIndex(inorder,st,end,preorder[preIndex]);

        TreeNode* root=new TreeNode(preorder[preIndex]);
        preIndex++;
        root->left=Solve(preorder,inorder,preIndex,st,index-1);
        root->right=Solve(preorder,inorder,preIndex,index+1,end);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex=0;
        int n=inorder.size();
        TreeNode* root=Solve(preorder,inorder,preIndex,0,n-1);
        return root;
    }
};
