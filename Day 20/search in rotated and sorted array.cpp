class Solution {
  public:
  int findMinInRotatedSortedArray(vector<int>& arr)
  {
      int n=arr.size();
      int l=0;
      int r= arr.size()-1;
      int ans=-1;
      while(l < r)
      {
          int mid = l + (r-l)/2;
          if(arr[mid] > arr[r])
          {
              l=mid+1;
          }
          else{
              r = mid;
          }
      }
      return r;
  }
  int binarySearch(vector<int>&arr, int l, int r, int key)
  {
      while(l <= r)
      {
         int mid = l + (r-l)/2;
         if(arr[mid] == key)return mid;
         else if(arr[mid] > key)
         {
             r=mid-1;
         }
         else{
             l=mid+1;
         }
      }
      return -1;
  }
    int search(vector<int>& arr, int key) {
       
       
       int minIndex = findMinInRotatedSortedArray(arr);
       
       int ans1 = binarySearch(arr, 0,minIndex-1,key);
       int ans2 = binarySearch(arr, minIndex, arr.size()-1,key);
       if(ans1 >= 0)return ans1;
       else if(ans2 >= 0)return ans2;
       return -1;
       
        
    }
};
