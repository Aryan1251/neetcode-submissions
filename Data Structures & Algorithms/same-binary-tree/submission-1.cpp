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
    bool Solve(TreeNode* p,TreeNode* q)
    {
        if(p==NULL && q==NULL) return true;
        if(p!=NULL && q==NULL) return false;
        if(p==NULL && q!=NULL) return false;
        
        bool leftPart=Solve(p->left,q->left);
        bool rightPart=Solve(p->right,q->right);

        if(leftPart && rightPart && p->val==q->val) return true;
        return false;

    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans=Solve(p,q);
        return ans;
    }
};
