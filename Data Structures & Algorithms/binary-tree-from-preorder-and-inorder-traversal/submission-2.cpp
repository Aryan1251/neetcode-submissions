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
    int findIndex(vector<int>& inorder,int val)
    {
        int n=inorder.size();
        for(int i=0;i<n;i++)
        {
            if(inorder[i]==val) return i;
        }
        return -1;
    }
    TreeNode* Solve(vector<int>& preorder,vector<int>& inorder,int st,int end,int &ind)
    {
        if(ind>=preorder.size() || st>end) return nullptr;

        int val=preorder[ind];
        ind+=1;
        int index=findIndex(inorder,val);

        TreeNode* root=new TreeNode(val);
        root->left=Solve(preorder,inorder,st,index-1,ind);
        root->right=Solve(preorder,inorder,index+1,end,ind);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ind=0,n=inorder.size();
        TreeNode* root=Solve(preorder,inorder,0,n-1,ind);
        return root;
    }
};
