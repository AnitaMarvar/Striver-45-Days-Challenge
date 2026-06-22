//tle 

class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        vector<int>ans;
        
        //min heap
        
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<b.size();j++)
            {
                int sum = a[i] + b[j];
                pq.push(sum);
                
                if(pq.size() > k)
                {
                    pq.pop();
                }
            }
        }
        
        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
