class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        
        vector<pair<double, int>>items;
        
        for(int i=0;i<n;i++)
        {
            items.push_back({(double)val[i]/wt[i], i});
        }
        
        sort(items.rbegin(), items.rend());
        
        double ans=0.0;
        
        for(auto it : items)
        {
            int i = it.second;
            
            if(capacity >= wt[i])
            {
                capacity -= wt[i];
                ans += val[i];
            }
            else{
                ans += it.first * capacity;
                break;
            }
        }
        return ans;
    }
};
