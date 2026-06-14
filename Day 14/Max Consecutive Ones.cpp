class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int maxi = INT_MIN;

        for(int x : nums)
        {
            if(x == 0)
            {
                ans = 0;
            }
            else{
                ans++;
            }
            maxi = max(maxi, ans);
        }
        return maxi;
    }
};
