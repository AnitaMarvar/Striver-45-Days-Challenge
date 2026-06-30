class Trie{
    public: 
    int cntOfLetter;
    bool endOfWord;
    Trie *children[26];

    Trie(){
        cntOfLetter=0;
        endOfWord=false;
        for(int i=0;i<26;i++)
        {
            children[i] = NULL;
        }
    }

    void insert(Trie *root,string &word)
    {
        Trie *crawler = root;
        for(int i=0;i<word.length();i++)
        {
            int ind = word[i] - 'a';
            if(crawler->children[ind]==NULL)
            {
                crawler->children[ind] = new Trie();
            }
            crawler=crawler->children[ind];
             crawler->cntOfLetter++;
        }
         crawler->endOfWord = true;
    }
};
class Solution {
public:
    
    string longestCommonPrefix(vector<string>& strs) {
        //brute force tc O(n)
    //     string ans="";
    //    bool cnt=true;
    //     string word = strs[0];
    //     for(int i=0;i<word.length();i++)
    //     {
    //         char cht = word[i];
    //         for(int j=1;j<strs.size();j++)
    //         {
    //             string rest = strs[j];
    //             if(rest[i] != cht)
    //             {
    //                 cnt=false;
    //             } 
    //         }
    //         if(cnt==false)return ans;
    //         else{
    //             ans += cht;
    //         }
    //     }
    //     return ans;


           //using TRIE 
           if(strs.size()==1)return strs[0];
           Trie *root = new Trie();
           for(int i=0;i<strs.size();i++)
           {
             root->insert(root,strs[i]);
           }
            int n = strs.size();
           string ans="";
           string word = strs[0];
           Trie *crawler = root;

           for(int i=0;i<word.length();i++)
           {
             int ind = word[i]-'a';
             if(crawler->children[ind]==NULL)return ans;
             else if(crawler->children[ind] && crawler->children[ind]->cntOfLetter == n)
             {
                crawler = crawler->children[ind];
                ans += word[i];
             }
           }
           return ans;
           
    }
};
