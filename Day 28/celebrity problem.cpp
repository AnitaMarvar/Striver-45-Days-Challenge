class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        
        int n=mat.size();
        stack<int>st;
        
        for(int i=0;i<n;i++)
        {
            st.push(i);
        }
        while(st.size() > 1)
        {
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();
            
            if(mat[first][second]==1)
            {
                st.push(second);
            }
            else{
                st.push(first);
            }
        }
        if(st.empty())return -1;
        int ans=st.top();
        st.pop();
        int rowSum=0, colSum=0;
        for(int i=0;i<n;i++)
        {
            rowSum += mat[ans][i];
            colSum += mat[i][ans];
        }
        rowSum -= mat[ans][ans];
        colSum -= mat[ans][ans];
        if(rowSum==0 && colSum==n-1)return ans;
        return -1;
    }
};
