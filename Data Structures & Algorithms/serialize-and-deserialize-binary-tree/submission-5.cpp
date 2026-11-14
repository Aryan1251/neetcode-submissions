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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";

        string str;
        queue<TT>q;

        q.push(root);
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            if(node)
            {
                str+=to_string(node->val);
                str+=",";
            }
            else
            {
                str+="N";
                str+=",";
            }

            if(node){
                q.push(node->left);
                q.push(node->right);
            }
        }
        str.pop_back();
        cout<<str<<endl;
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // return nullptr;
        if(data.empty()) return nullptr;
        queue<TT>q;
        int index=0,n=data.size();

        string s;
        while(data[index]!=',' && index<n)
        {
            s+=data[index];
            index++;
        }

        int num=stoi(s);
        TT root=new TreeNode(num);
        index++;
        q.push(root);
        while(index<n)
        {
            auto node=q.front();
            q.pop();

            // char node_left=data[index];
            string node_left;
            while(data[index]!=',' && index<n)
            {
                node_left+=data[index];
                index++;
            }
            // char node_right=data[index+1];
            index++;
            string node_right;
            while(data[index]!=',' && index<n)
            {
                node_right+=data[index];
                index++;
            }

            if(node_left=="N")
            {
                node->left=nullptr;
            }else
            {
                int left_num=stoi(node_left);
                TT leftNode=new TreeNode(left_num);
                node->left=leftNode;
                q.push(leftNode);
            }
            if(node_right=="N")
            {
                node->right=nullptr;
            }else
            {
                int right_num=stoi(node_right);
                TT rightNode=new TreeNode(right_num);
                node->right=rightNode;
                q.push(rightNode);
            }
            index+=1;
        }
        return root;
    }
};
           