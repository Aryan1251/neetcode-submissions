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

#define TT TreeNode*

class Solution {
    bool ans=0;
    string Solve(TT root)
    {
        if(!root) 
        return "N";

        string str;
        string leftPart=Solve(root->left);
        string rightPart=Solve(root->right);

        str+=leftPart;
        str+=to_string(root->val);
        str+=rightPart;

        return str;
    }
    string chkValid(TT root,string s)
    {
        if(!root) 
        return "N";

        string str;
        string leftPart=chkValid(root->left,s);
        string rightPart=chkValid(root->right,s);

        str+=leftPart;
        str+=to_string(root->val);
        str+=rightPart;

        if(s==str) ans=1;

        return str;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string s=Solve(subRoot);
        chkValid(root,s);
        return ans;
    }
};
