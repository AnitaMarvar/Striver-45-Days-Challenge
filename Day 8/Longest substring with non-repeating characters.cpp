class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int maxlen=-1;
        
        int l=0, r=0;
        unordered_map<int,int>mp; //[char, freq]
        
        while(r < s.length())
        {
            mp[s[r]]++;
            
            while(mp[s[r]] > 1)
            {
                mp[s[l]]--;
                if(mp[s[l]]==0)
                {
                    mp.erase(s[l]);
                }
                l++;
            }
            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};
