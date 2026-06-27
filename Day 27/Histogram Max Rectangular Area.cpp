class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        //find the next smaller element and previous smaller element
        int n=arr.size();
        stack<int>st;
        vector<int>nse(n), pse(n);  //store the indices because we want width
        
        //next smaller element
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            
            if(st.empty())
            {
                nse[i]=n;   //becuase to find width
            }
            else{
                nse[i] = st.top();
            }
            
            st.push(i);
        }
        while(!st.empty())st.pop();
        //prev smaller ele
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            
            if(st.empty())
            {
                pse[i]=-1;
            }
            else{
                pse[i] = st.top();
            }
            
            st.push(i);
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            int width = nse[i] - pse[i] - 1;
            ans = max(ans, arr[i] * width);
        }
        return ans;
        
        
        
        
    }
};
