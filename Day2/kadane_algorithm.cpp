class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //kadanes algo

        int maxSum = INT_MIN;
        int currSum = 0;

        for(int x : nums)
        {
            currSum = max(x, currSum + x);  // make a new subarray or continue with the current subarray
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
