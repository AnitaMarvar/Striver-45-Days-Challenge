class Solution {
  public:
    int single(vector<int>& arr) {
        int ans=0;
        
        for(int i=0;i<arr.size();i++)
        {
            ans ^= arr[i];
        }
        return ans;
        
    }
};
