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
    string getMapping(TreeNode* root)
    {
        if(!root) return "N";

        string leftPart=getMapping(root->left);
        string rightPart=getMapping(root->right);

        string str=leftPart+to_string(root->val)+rightPart;

        return str;
    }
    bool ans=false;
    string Solve(TreeNode* root,string s)
    {
        if(!root) return "N";

        string leftPart=Solve(root->left,s);
        string rightPart=Solve(root->right,s);

        string str=leftPart+to_string(root->val)+rightPart;

        if(str==s) ans=true;

        return str;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string str=getMapping(subRoot);
        Solve(root,str);
        return ans;
    }
};
