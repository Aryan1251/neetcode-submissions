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
        if(!root) return {};
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<vector<int> >ans;
        vector<int>v;
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            if(node!=NULL) v.push_back(node->val);

            if(node==NULL)
            {
                ans.push_back(v);
                v.clear();
                if(!q.empty()) q.push(NULL);
            }
            
            if(node && node->left) q.push(node->left);
            if(node && node->right) q.push(node->right);
        }
        return ans;
    }
};
