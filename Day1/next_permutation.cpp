class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        //step1
        int n=nums.size();
        int pivot_ind= -1;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i] < nums[i+1])
            {
                pivot_ind = i;
                break;
            }
        }

        //step2
        if(pivot_ind != -1){
        int j=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i] > nums[pivot_ind])
            {
                j=i;
                break;
            }
        }
        swap(nums[pivot_ind], nums[j]);
    }
        //step3
        reverse(nums.begin() + pivot_ind + 1, nums.end());
    }
};
