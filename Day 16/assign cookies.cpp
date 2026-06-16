class Solution {
  public:
    int maxChildren(vector<int> &greed, vector<int> &cookie) {
         int n=greed.size();
        int m=cookie.size();
        
        // code here
        sort(greed.begin(), greed.end());
        sort(cookie.begin(), cookie.end());
        
       
        int i=0;
        int j=0;
        
        while(i < n && j < m)
        {
            if(cookie[j] >= greed[i])
            {
                i++;
            }
            j++;
        }
        return i;
    }
};
