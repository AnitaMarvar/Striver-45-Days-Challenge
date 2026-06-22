class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        vector<int>all;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                all.push_back(mat[i][j]);
            }
        }
        sort(all.begin(),all.end());
        int n=all.size();
        return all[n/2];
    }
};
