class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>arr(n * n+1, 0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int ele = grid[i][j];
                arr[ele]++;
            }
        }
        int missing=-1;
        int repeating=-1;
        for(int i=1;i<=(n*n);i++)
        {
            if(arr[i] == 2)
            {
                repeating=i;
            }
        }
        for(int i=1;i<=(n*n);i++)
        {
            if(arr[i] == 0)
            {
                missing=i;
            }
        }
        return {repeating,missing};

        
    }
};
