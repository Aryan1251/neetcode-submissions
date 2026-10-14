class Trie{
    public:
    char data;
    Trie* child[26];
    bool isTerminal;

    Trie(char data)
    {
        this->data=data;
        for(int i=0;i<26;i++)
        this->child[i]=nullptr;
        this->isTerminal=false;
    }
};


class PrefixTree {
public:
    Trie* root=new Trie('-');
    PrefixTree() {
        
    }
    void insertUtil(string word,Trie* root)
    {
        if(word.empty())
        {
            root->isTerminal=true;
            return ;
        }

        int ind=word[0]-'a';
        if(root->child[ind])
        {
            root=root->child[ind];
        }else
        {
            Trie* childNode=new Trie(word[0]);
            root->child[ind]=childNode;
            root=childNode;
        }
        insertUtil(word.substr(1),root);
    }
    void insert(string word) {
        insertUtil(word,root);
    }

    bool searchUtil(string word,Trie* root)
    {
        if(word.empty())
        {
            return root->isTerminal;
        }

        int ind=word[0]-'a';
        if(root->child[ind])
        {
            root=root->child[ind];
            return searchUtil(word.substr(1),root);
        }else
        return false;
    }
    bool search(string word) {
        return searchUtil(word,root);
    }
    
    bool startsWith(string prefix,Trie* root)
    {
        if(prefix.empty())
        return true;

        int ind=prefix[0]-'a';
        if(root->child[ind])
        {
            root=root->child[ind];
            return startsWith(prefix.substr(1),root);
        }else
        return false;
    }
    bool startsWith(string prefix) {
        return startsWith(prefix,root);
    }
};
