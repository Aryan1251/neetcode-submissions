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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        if(!root) return {};
        q.push(root);
        q.push(nullptr);
        vector<vector<int> >ans;
        vector<int>v;
        while(!q.empty())
        {
            auto node=q.front();
            if(node) v.push_back(node->val);
            q.pop();
            if(node==NULL)
            {
                ans.push_back(v);
                v.clear();
                if(!q.empty()) q.push(nullptr);
            }
            if(node && node->left)
            q.push(node->left);
            if(node && node->right)
            q.push(node->right);
        }
        return ans;
    }
};
