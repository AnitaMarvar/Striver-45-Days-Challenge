class Solution {
public:
    int solve(vector<vector<int>>&grid, int srcR, int srcC, vector<vector<int>>&dp)
    {
        if(srcR==grid.size()-1 && srcC == grid[0].size()-1)
        {
            return 1;
        }
        if(srcR >= grid.size() || srcC >= grid[0].size() || srcR < 0 || srcC < 0)
        {
            return 0;
        }
          if(dp[srcR][srcC]!=-1)return dp[srcR][srcC];
        int down = solve(grid, srcR + 1, srcC,dp);
        int right = solve(grid, srcR, srcC+1,dp);
        return dp[srcR][srcC]=down + right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>grid(m, vector<int>(n,1));
        vector<vector<int>>dp(m, vector<int>(n,-1));
        

        return solve(grid, 0,0,dp);
    }
};
