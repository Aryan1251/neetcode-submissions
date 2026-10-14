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
        queue<TreeNode*>q;
        q.push(root);
        string str;
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            if(node==NULL)
            {
                str+="N";
                str+=",";
            }
            else
            {
                str+=to_string(node->val);
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
        if(data=="") return NULL;
        stringstream str(data);
        string s;
        getline(str,s,',');
        int num=stoi(s);
        TreeNode* root=new TreeNode(num);
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            auto node=q.front();
            q.pop();

            //leftPart
            getline(str,s,',');
            if(s=="N") node->left=NULL;
            else
            {
                int num=stoi(s);
                TreeNode* leftPart=new TreeNode(num);
                node->left=leftPart;
                q.push(leftPart);
            }

            //rightPart
            getline(str,s,',');
            if(s=="N") node->right=NULL;
            else
            {
                num=stoi(s);
                TreeNode* rightPart=new TreeNode(num);
                node->right=rightPart;
                q.push(rightPart);
            }
        }
        return root;
    }
};
