//tle --> brute force

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

    //optimal approach
    
class Solution {
  public:
  
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        vector<int>ans;
        
        sort(a.begin(),a.end(), greater<int>());
        sort(b.begin(), b.end(),greater<int>());
        
        int n=a.size();
        //maxheap;
        priority_queue<tuple<int,int,int>>maxheap;
        int maxSum = a[0] + b[0];

        set<pair<int,int>>vis;  //to avoid visiting the elements again
        
        maxheap.push({maxSum, 0,0});
        vis.insert({0,0});
        
        while(k-- && !maxheap.empty())
        {
            auto [maxSum, i,j] = maxheap.top();
            maxheap.pop();
            ans.push_back(maxSum);
            
            if(i+1 < n && !vis.count({i+1,j}))
            {
                maxSum = a[i+1] + b[j];
                maxheap.push({maxSum, i+1,j});
                vis.insert({i+1,j});
            }
            if(j+1 < n && !vis.count({i,j+1}))
            {
                maxSum  = a[i] + b[j+1];
                maxheap.push({maxSum, i,j+1});
                vis.insert({i,j+1});
            }
        }
        return ans;
    }
};
};
