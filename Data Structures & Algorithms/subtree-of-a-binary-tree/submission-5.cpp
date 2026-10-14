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
    bool ans=0;
    string Solve(TreeNode* root)
    {
        if(!root) return "N";

        string str;
        string leftPart=Solve(root->left);
        string rightPart=Solve(root->right);

        str+=leftPart+","+to_string(root->val)+","+rightPart;

        return str;

    }
   string chk(TreeNode* root,string s)
    {
        if(!root || ans==1) return "N";

        string str;
        string leftPart=chk(root->left,s);
        string rightPart=chk(root->right,s);

        str+=leftPart+","+to_string(root->val)+","+rightPart;
        if(s==str) ans=1;

        return str;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       string str= Solve(subRoot);
       chk(root,str);
       return ans;
    }
};
