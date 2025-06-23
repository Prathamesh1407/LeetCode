class Trie {
    struct trieNode
    {
        bool isEndOfWord;
        trieNode* children[26];
    };
    trieNode* getNode()
    {
        trieNode* newNode=new trieNode();

        newNode->isEndOfWord=0;
        for(int i=0;i<26;i++)
        {
            newNode->children[i]=NULL;
        }
        return newNode;
    }
public:
    trieNode* root;
    Trie() {
        root=getNode();
    }
    
    void insert(string word) {
        trieNode* crawler=root;

        for(auto val:word)
        {
            if(crawler->children[val-'a']==NULL) crawler->children[val-'a']=getNode();
            crawler=crawler->children[val-'a'];
        }
        //End of word
        crawler->isEndOfWord=1;
    }
    
    bool search(string word) {
        trieNode* crawler=root;

        for(auto val:word)
        {
            if(crawler->children[val-'a']==NULL) return 0;
            crawler=crawler->children[val-'a'];
        }
        if(crawler!=NULL && crawler->isEndOfWord==1) return 1;
        return 0;
    }
    
    bool startsWith(string prefix) {
        trieNode* crawler=root;
        int i;
        for(i=0;i<prefix.length();i++)
        {
            if(crawler->children[prefix[i]-'a']==NULL) return 0;
            crawler=crawler->children[prefix[i]-'a'];
        }
        if(i==prefix.length()) return 1;
        return 0;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */