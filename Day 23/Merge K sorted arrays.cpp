class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        //minheap
        priority_queue<int, vector<int>, greater<int>>pq;
       for(int i=0;i<mat.size();i++)
       {
           for(int j=0;j<mat[0].size();j++)
           {
               pq.push(mat[i][j]);
           }
       }
       vector<int>ans;
       while(!pq.empty())
       {
           ans.push_back(pq.top());
           pq.pop();
       }
       return ans;
        
    }
};
