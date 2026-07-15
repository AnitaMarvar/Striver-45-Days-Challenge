class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
       
       //dont change the original input
       vector<vector<int>> grid = image;
       
       int ogColor = image[sr][sc];
       
        vector<vector<int>>dir = {{0,-1},{-1,0},{0,1},{1,0}};
        
        queue<pair<int,int>>q;
        if(grid[sr][sc]==ogColor)
        {
         q.push({sr, sc});
         grid[sr][sc] = newColor;
        }
        
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for(auto it : dir)
            {
                int newI = it[0] + i;
                int newJ = it[1] + j;
                
                if(newI < 0 || newJ < 0 || newI >= grid.size() || newJ >= grid[0].size() || grid[newI][newJ] == newColor)
                {
                    continue;
                }
                if(grid[newI][newJ] == ogColor)
                {
                    grid[newI][newJ] = newColor;
                    q.push({newI, newJ});
                }
            }
        }
        return grid;
    }
};
