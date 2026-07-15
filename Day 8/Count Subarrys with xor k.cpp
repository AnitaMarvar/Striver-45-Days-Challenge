class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        long cnt=0;
        
        int xorSum = 0;
        
        unordered_map<int,int>mp;   //[xor , freq]
        
        for(auto it : arr)
        {
            xorSum ^= it;
            
            if(xorSum == k)  //for first xor 
            {
                cnt++;
            }
            
            if(mp.find(xorSum ^ k) != mp.end())
            {
                cnt += mp[xorSum ^ k];
            }
            
            mp[xorSum]++;
        }
        return cnt;
    }
};
