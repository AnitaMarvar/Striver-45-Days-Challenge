class Solution {
  public:
    int nthRoot(int n, int m) {
        if(m==0)return 0;
       int low=1;
       int high=m;
       
       while(low <= high)
       {
           int mid = low + (high - low)/2;
           long long val=1;
           
           for(int i=0;i<n;i++)
           {
               val *= mid;
           }
           if(val == m)
           {
               return mid;
           }
           else if(val > m)
           {
               high = mid-1;
           }
           else{
               low = mid+1;
           }
       }
       return -1;
        
    }
};
