//brute force
#include <bits/stdc++.h> 
long long getInversions(long long *arr, int n){
    long long ans=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i] > arr[j])
            {
                ans++;
            }
        }
    }
    return ans;
}

//using merge sort
#include <bits/stdc++.h> 
long long merge(long long *arr, int l, int high, int mid)
{
    vector<int>temp;
    int left = l;
    int right = mid+1;
    long long cnt=0;

    while(left <= mid && right <= high)
    {
        if(arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else{
            cnt += (mid - left + 1);
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid)
    {
        temp.push_back(arr[left]);
            left++;
    }
    while(right <= high)
    {
        temp.push_back(arr[right]);
            right++;
    }
    for(int i=l ;i <=high;i++)
    {
        arr[i] = temp[i-l];
    }
    return cnt;

}
long long mergeSort(long long *arr, int l, int r)
{
    if(l >= r)return 0;
    int mid = l + (r-l)/2;
    long long cnt=0;

    cnt += mergeSort(arr,l,mid);
    cnt += mergeSort(arr,mid+1,r);

    cnt += merge(arr, l,r,mid);
    return cnt;
}
long long getInversions(long long *arr, int n){
    return mergeSort(arr, 0,n-1);
}
