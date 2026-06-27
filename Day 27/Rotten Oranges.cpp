class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        int fresh=0;
        
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==2)
                {
                    q.push({i,j});
                }
                else if(mat[i][j]==1)
                {
                    fresh++;
                }
            }
        }
        if(fresh==0)return 0;
        vector<int>dx = {-1,0,1,0};
        vector<int>dy = {0,1,0,-1};
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m,false));
        int time=0;
        
        while(!q.empty())
        {
            int sz = q.size();
            
            while(sz--){
            int x = q.front().first;
            int y = q.front().second;
           
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int nx = dx[i] + x;
                int ny = dy[i] + y;
                
                if(nx < 0 || nx >= mat.size() || ny < 0 || ny >= mat[0].size() || mat[nx][ny]==0 || vis[nx][ny]==true)continue;
                if(mat[nx][ny]==1)
                {
                    vis[nx][ny]=true;
                    mat[nx][ny]=2;
                    fresh--;
                    q.push({nx,ny});
                }
            }
                
            }
            time++;
        }
        if(fresh > 0)return -1;
        return time-1;
        
    }
};
