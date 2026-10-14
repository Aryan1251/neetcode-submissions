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
        str+=to_string(root->val);
        str+=",";
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            
            if(node->left)
            {
                q.push(node->left);
                str+=to_string(node->left->val);
                str+=",";
            }else
            {
                str+="N";
                str+=",";
            }
            if(node->right)
            {
                q.push(node->right);
                str+=to_string(node->right->val);
                str+=",";
            }
            else
            {
                str+="N";
                str+=",";
            }
        }
        str.pop_back();
        cout<<str;
        cout<<endl;
        return str;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return nullptr;
        stringstream s(data);
        string str;
        getline(s,str,',');
        int num=stoi(str);
        TreeNode* root=new TreeNode(num);
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();

            getline(s,str,',');
            if(str!="N")
            {
                int num=stoi(str);
                TreeNode* leftPart=new TreeNode(num);
                node->left=leftPart;
                q.push(leftPart);
            }else
            {
                node->left=nullptr;
            }
            getline(s,str,',');
            if(str!="N")
            {
                int num=stoi(str);
                TreeNode* rightPart=new TreeNode(num);
                node->right=rightPart;
                q.push(rightPart);
            }else
            {
                node->right=nullptr;
            }
        }
        return root;
    }
};
