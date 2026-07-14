#include <queue>
#include <vector>
vector<int> findMedian(vector<int> &arr, int n){
	priority_queue<int>maxpq;
    priority_queue<int,vector<int>,greater<int>>minpq;
    vector<int>ans;

    for(int i=0;i<n;i++)
    {
      //step 1 : push
        if(maxpq.empty() || maxpq.top() > arr[i])
        {
            maxpq.push(arr[i]);
        }
        else{
            minpq.push(arr[i]);
        }

      //step2 : pop
        if(maxpq.size() > minpq.size() + 1)
        {
            minpq.push(maxpq.top());
            maxpq.pop();
        }
        else if(minpq.size() > maxpq.size() +1)
        {
            maxpq.push(minpq.top());
            minpq.pop();
        }

        //step3 : find median
        if(maxpq.size() == minpq.size())
        {
            ans.push_back((maxpq.top() + minpq.top())/2);
        }
        else{
            if(maxpq.size() > minpq.size())
            {
                ans.push_back(maxpq.top());
            }
            else{
                ans.push_back(minpq.top());
            }
        }
    }
    return ans;
	
}
