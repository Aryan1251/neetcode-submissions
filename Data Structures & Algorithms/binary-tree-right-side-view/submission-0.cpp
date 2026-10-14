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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        map<int,int>mp;
        queue<pair<int,TreeNode*> >q;
        vector<int>ans;
        q.push({0,root});
        while(!q.empty())
        {
            int lvl=q.front().first;
            TreeNode* root=q.front().second;
            q.pop();
            mp[lvl]=root->val;
            if(root->left)
            q.push({lvl+1,root->left});
            if(root->right)
            q.push({lvl+1,root->right});
        }
        for(auto it: mp)
        ans.push_back(it.second);

        return ans;
    }
};
