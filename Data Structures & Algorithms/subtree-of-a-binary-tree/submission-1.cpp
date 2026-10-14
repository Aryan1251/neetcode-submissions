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
    string Solve(TreeNode* root)
    {
        if(root==NULL) return "N";

        string leftPart=Solve(root->left);
        string rightPart=Solve(root->right);
        string s=to_string(root->val);

        s=s+","+leftPart+","+rightPart;

        return s;
    }
    string SolveTree(TreeNode* root,string str,bool& ans)
    {
        if(!root) return "N";

        string leftPart=SolveTree(root->left,str,ans);
        string rightPart=SolveTree(root->right,str,ans);
        string s=to_string(root->val);

        s=s+","+leftPart+","+rightPart;
        if(s==str) ans=true;
        return s;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string str=Solve(subRoot);
        bool ans=0;
        SolveTree(root,str,ans);
        return ans;
    }
};
