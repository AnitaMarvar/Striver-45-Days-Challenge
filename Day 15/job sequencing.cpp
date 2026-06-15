  bool static cmp(Job &a, Job &b)
    {
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) {

        sort(arr, arr + n, cmp);
        
        int maxDead = 0;
        
        for(int i=0;i<n;i++)
        {
            maxDead = max(maxDead, arr[i].deadline);
        }
        
        vector<bool>slot(maxDead+1, false);
        
        int jobsDone=0;
        int maxProfit=0;
        for(int i=0;i<n;i++)
        {
            for(int j=arr[i].deadline;j>0;j--)
            {
                if(slot[j]==false)
                {
                    slot[j]=true;
                    jobsDone++;
                    maxProfit += arr[i].profit;
                    break;
                }
            }
        }
        return {jobsDone, maxProfit};
