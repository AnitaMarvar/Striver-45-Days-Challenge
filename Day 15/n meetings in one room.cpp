class Solution {
  public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        // code here
        vector<tuple<int,int,int>>arr;
        vector<int>ans;
        
        for(int i=0;i<s.size();i++)
        {
            arr.push_back({f[i], s[i], i+1});
        }
        sort(arr.begin(), arr.end());
        
        int lastEndTime = -1;
        
        for(int i=0;i<arr.size();i++)
        {
            int stTime = get<1>(arr[i]);
            int finTime = get<0>(arr[i]);
            int ind = get<2>(arr[i]);
            
            if(lastEndTime < stTime)
            {
                lastEndTime = finTime;
                ans.push_back(ind);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
        
    }
};
