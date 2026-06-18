#include <algorithm>
#include <set>
void permute(string &str, vector<string>&ans,int index, int n)
{
    if(index+1 >= n)
    {
        ans.push_back(str);
        return;
    }
    
    for(int i=index;i<n;i++)
    {
        swap(str[i],str[index]);
        permute(str,ans,index+1,n);
        swap(str[i],str[index]);
    }
    //permute(str,ans,index+1,n);
}
vector<string> generatePermutations(string &str)
{
    vector<string>ans;
    int n=str.length();
    permute(str,ans,0,n);
   set<string>sets;
   for(int i=0;i<ans.size();i++)
   {
       sets.insert(ans[i]);
   }
   vector<string>result;
   for(auto i: sets)
   {
       result.push_back(i);
   }
  

    return result;
}
