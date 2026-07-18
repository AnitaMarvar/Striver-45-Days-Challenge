class Solution {
  public:
    void solve(unordered_map<int,vector<int>>&mp, vector<int>&ans,vector<bool>&vis, int node)
    {
        ans.push_back(node);
        vis[node] = true;
        
        for(auto it : mp[node])
        {
            if(!vis[it])
            {
                solve(mp,ans,vis, it);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
       vector<int>ans;
       unordered_map<int, vector<int>>mp;
       int n = adj.size();
       vector<bool>vis(n+1,false);
       for(int i=0;i<n;i++)
       {
           int u = i;
           
           for(auto it : adj[i])
           {
               int v = it;
               mp[u].push_back(it);
           }
       }
       
       for(int i=0;i<n;i++)
       {
           if(!vis[i])
           {
               solve(mp, ans, vis, i);
           }
       }
       return ans;
    }
};
