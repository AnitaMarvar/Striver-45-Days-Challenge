class Solution {
  public:
    string reverseWords(string &s) {
       string ans="";
       
       int i=0;
       int n=s.length();
       while(i < n)
       {
           while(i < n && s[i]==' ')
           {
               i++;
           }
           if(i >= n)break;
           
           string word="";
           while(i < n && s[i] != ' ')
           {
               word += s[i];
               i++;
           }
           reverse(word.begin(), word.end());
           
           if(!ans.empty())ans += " "; 
           ans += word;
           
       }
       return ans;
        
    }
};
