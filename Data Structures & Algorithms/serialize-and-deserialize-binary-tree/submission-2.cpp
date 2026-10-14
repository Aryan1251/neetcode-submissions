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
        string str;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();

            if(node==nullptr) str+='X';
            else
            {
                string s=to_string(node->val);
                str+=s;
            }

            str+=',';
            if(node)
            q.push(node->left);
            if(node)
            q.push(node->right);
        }
        if(!str.empty())
        str.pop_back();

        // cout<<str<<" ";
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;

        stringstream str(data);
        string s;
        getline(str,s,',');
        
        if(s=="X") return nullptr;

        int val=stoi(s);
        TreeNode* root=new TreeNode(val);
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            getline(str,s,',');

            if(s=="X")
            {
                node->left=nullptr;
            }else
            {
                int val=stoi(s);
                TreeNode* leftNode=new TreeNode(val);
                node->left=leftNode;
                q.push(leftNode);
            }
            getline(str,s,',');
            if(s=="X")
            {
                node->right=nullptr;
            }else
            {
                int val=stoi(s);
                TreeNode* rightNode=new TreeNode(val);
                node->right=rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};
