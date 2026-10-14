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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string str;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            if(node==NULL)
            {
                str+="N";
                str+=",";
            }else
            {
                str+=to_string(node->val)+",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        str.pop_back();
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;

        stringstream str(data);
        string s;
        getline(str,s,',');

        TreeNode* root=new TreeNode(stoi(s));
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            auto node=q.front();
            q.pop();

            getline(str,s,',');
            if(s=="N") node->left=nullptr;
            else
            {
                TreeNode* left_node=new TreeNode(stoi(s));
                node->left=left_node;
                q.push(node->left);
            }
            getline(str,s,',');
            if(s=="N") node->right=nullptr;
            else
            {
                TreeNode* right_node=new TreeNode(stoi(s));
                node->right=right_node;
                q.push(node->right);
            }
        }
        return root;
    }
};
