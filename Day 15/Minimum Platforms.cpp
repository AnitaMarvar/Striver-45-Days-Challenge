class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        
       // we want the arrival here At is imp
       
       vector<pair<int, int>>trains;
       
       for(int i=0;i<arr.size();i++)
       {
           trains.push_back({arr[i], dep[i]});
       }
       
       sort(trains.begin(), trains.end());
       
       priority_queue<int, vector<int>, greater<int>>pq;
       
       int maxi=1;
       
       for(int i=0;i<trains.size();i++)
       {
           int arrivalTime = trains[i].first;
           int depTime = trains[i].second;
           
           while(!pq.empty() && pq.top() < arrivalTime)  //gaya pahele ka train
           {
               pq.pop();
           }
           pq.push(depTime);
           
           maxi = max(maxi, (int)pq.size());
       }
       return maxi;
        
    }
};
