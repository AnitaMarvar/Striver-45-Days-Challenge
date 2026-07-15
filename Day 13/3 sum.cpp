class Solution {
  public:
    vector<vector<int>> triplets(vector<int> &arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        // 1 fixed. 2 positional
        
        int n = arr.size();
        
        
        for(int i=0;i<n-2;i++)
        {
            if(i > 0 && arr[i] == arr[i-1])continue;
            int left = i+1;
            int right = n-1;
            
            while(left < right)
            {
                int sum = arr[i] + arr[left] + arr[right];
                if(sum == 0)
                {
                    ans.push_back({arr[i] , arr[left] , arr[right]});
                    while(left < right && arr[left] == arr[left + 1])left++;
                    while(left < right && arr[right] == arr[right-1])right--;
                    left++;
                    right--;
                }
                else if(sum > 0)
                {
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return ans;
        
        
    }
};
