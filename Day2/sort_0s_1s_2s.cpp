class Solution {
public:
    void sortColors(vector<int>& nums) {

        //approach 1
        sort(nums.begin(), nums.end());

        //approach 2 -- dutch falg algorithm

        int l = 0;
        int mid = 0;
        int n=nums.size();
        int r = n-1;

        while(mid <= r)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid], nums[l]);
                l++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else{
                swap(nums[mid], nums[r]);
                r--;  // we need to check the mid because mid has r element which is not traversed before, thats why no mid++
            }
        }
        
    }
};
