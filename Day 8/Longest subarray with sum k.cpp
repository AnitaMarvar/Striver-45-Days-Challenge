class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
       
       unordered_map<int,int>mp;  //{sum and index]
       int n = arr.size();
       int sum = 0;
       int maxlen = 0;
       
       for(int i=0;i<n;i++)
       {
           sum += arr[i];
           if(sum == k)  //check first index also 
           {
               maxlen = i+1;
           }
           if(mp.find(sum - k) != mp.end())
           {
               maxlen = max(maxlen, i - mp[sum-k]);
           }
           
           //store first occurrence to find the longest subarray
           if(mp.find(sum) == mp.end())
           {
                mp[sum] = i;   
           }
       }
       return maxlen;
    }
};
