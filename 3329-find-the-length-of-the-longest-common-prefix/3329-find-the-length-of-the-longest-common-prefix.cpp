struct Trie
{
    //bool isEndOfWord;
    Trie* children[10];
};
class Solution {

    Trie* getNode()
    {
        Trie* newNode=new Trie();

        for(int i=0;i<10;i++)
        {
            newNode->children[i]=NULL;
        }
        return newNode;
    }

    void insert(int num,Trie* t1)
    {
        string str=to_string(num);
        Trie* crawler=t1;
        for(auto val:str)
        {
            if(crawler->children[val-'0']==NULL)
            {
                crawler->children[val-'0']=getNode();
            }
            crawler=crawler->children[val-'0'];
        }
    }

    int search(int num,Trie* t1)
    {
        string str=to_string(num);
        Trie* crawler=t1;
        int c=0;
        for(auto val:str)
        {
            if(crawler->children[val-'0']==NULL)
            {
                return c;
            }
            c++;
            crawler=crawler->children[val-'0'];
        }
        return c;
    }

public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie* t1=getNode();
        int ans=0;
        for(auto val:arr1)
        {
            insert(val,t1);
        }

        for(auto val:arr2)
        {
            ans=max(ans,search(val,t1)); 
        }

        return ans;
    }
};