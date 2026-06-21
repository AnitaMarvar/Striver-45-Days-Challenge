bool isPossible(vector<int>&stalls, int mid, int k)
{
    int cnt=1;
    int lastPos = stalls[0];
    for(int i=1;i<stalls.size();i++)
    {
        if(stalls[i] - lastPos >= mid)
        {
            cnt++;
            lastPos=stalls[i];
        }
    }
    return cnt >= k;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //find the max distance
    sort(stalls.begin(),stalls.end());
    int n = stalls.size();
    int st = 1;
    int end = stalls[n-1] - stalls[0];
    int ans=-1;
    
    while(st <= end)
    {
        int mid = st + (end - st)/2;

        if(isPossible(stalls,mid,k))
        {
            ans = mid;
            st=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}
