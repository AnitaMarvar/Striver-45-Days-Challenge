class Solution {
  public:
    void solve(vector<int>&arr, int ind, vector<int>&ans, int sum)
    {
        if(ind==arr.size())
        {
            ans.push_back(sum);
            return;
        }
        
        solve(arr,ind+1, ans, sum+arr[ind]);
        
        solve(arr, ind+1, ans, sum);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        
        vector<int>ans;
        
        solve(arr,0,ans,0);
        return ans;
    }
};
