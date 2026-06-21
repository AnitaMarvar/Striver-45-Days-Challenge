bool isPossible(vector<int>&arr, int mid, int m)
{
    int studCnt=1;
    int pages = 0;

    for(int i=0;i<arr.size();i++)
    {
        if(pages + arr[i] <= mid)
        {
            pages += arr[i];
        }
        else{
            studCnt++;
            if(studCnt > m || arr[i] > mid)
            {
                return false;
            }
            pages = arr[i];
        }
    }
    return true;
}
int findPages(vector<int>& arr, int n, int m) {
    if(m > n)
    {
        return -1;
    }

    int sum=0;
    for(int x : arr)
    {
        sum += x;
    }
    int st=0;
    int end = sum;
    int ans=-1;
    int mid = st + (end - st)/2;

    while(st <= end)
    {
        if(isPossible(arr,mid, m))
        {
            ans = mid;
            end = mid-1;
        }
        else{
            st = mid+1;
        }
        mid = st + (end - st)/2;
    }
    return ans;
}
