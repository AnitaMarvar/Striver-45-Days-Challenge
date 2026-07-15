class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // //Tc : O(nlogn) sorting
        // if(nums.size()==0)
        // {
        //     return 0;
        // }
        // sort(nums.begin(),nums.end());
        // int maxi=1;
        // int curr_length=1;
        // for(int i=1;i<nums.size();i++)
        // {
        //     if(nums[i]==nums[i-1])
        //     {
        //         continue;
        //     }
        //     else if(nums[i] == nums[i-1]+1)
        //     {
        //         curr_length++;
        //         maxi = max(maxi, curr_length);
        //     }
        //     else{
        //         curr_length=1;
        //     }
        // }
        // return maxi;

        //Tc : O(n)
        if(nums.size()==0)return 0;
        int maxlen=0;
        unordered_set<int>sets; //lookup takes O(1)
        for(int i : nums)
        {
            sets.insert(i);
        }

        for(int x : sets)
        {
            if(sets.find(x-1) == sets.end())  // x = 1 , 0 is not there in set hence1 is the first in sequence, for x = 2, 1 is already there in sets no need for 2 as it would have been counted during itself
            {
               int len = 1;
               int curr = x;
               while(sets.find(curr+1) != sets.end()) // for 1, is 2(curr++) there, for 2(curr++) is 3 there
               {
                    len++;
                    curr++;
               }
               maxlen = max(maxlen, len);
            }
        }
        return maxlen;

    }
};
