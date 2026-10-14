class Solution {
    private:
    void Solve(TreeNode* root,int& k,int &ans)
    {
        if(!root) return ;

        Solve(root->left,k,ans);
        k--;
        if(k==0)
        ans=root->val;
        Solve(root->right,k,ans);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        Solve(root,k,ans);
        return ans;
    }
};
