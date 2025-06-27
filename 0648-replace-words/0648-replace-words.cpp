struct Trie
{
    bool isEndOfWord;
    Trie* children[26];
};
class Solution {
    Trie* getNode()
    {
        Trie* newNode=new Trie();

        newNode->isEndOfWord=0;
        for(int i=0;i<26;i++)
        {
            newNode->children[i]=NULL;
        }
        return newNode;
    }
    void insert(string word,Trie* t1) {
        Trie* crawler=t1;

        for(auto val:word)
        {
            if(crawler->children[val-'a']==NULL) crawler->children[val-'a']=getNode();
            crawler=crawler->children[val-'a'];
        }
        //End of word
        crawler->isEndOfWord=1;
    }


    string search(string word,Trie *t1) {
        Trie* crawler=t1;

        for(int i=0;i<word.size();i++)
        {
            if(crawler->children[word[i]-'a']==NULL) return word;
            crawler=crawler->children[word[i]-'a'];
            if(crawler->isEndOfWord==1) 
            {
                return word.substr(0,i+1);
            }
        }
        return word;
    }
public:
    string replaceWords(vector<string>& dict, string sentence) {
        Trie *t1=getNode();
        for(auto val:dict)
        {
            insert(val,t1);
        }
        string word="";
        string ans="";

        stringstream ss(sentence);

        while(getline(ss,word,' '))
        {
            ans+=search(word,t1);
            ans.push_back(' ');
        }

        ans.pop_back(); //for Last Extra Space
        
        return ans;
    }
};