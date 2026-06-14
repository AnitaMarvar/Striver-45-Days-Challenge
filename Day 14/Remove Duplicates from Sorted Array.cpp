class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int>mp;

        for(int i=0;i<nums.size();i++)
        {
            int ele = nums[i];
            mp[ele]++;
        }

        nums.clear();
        int ans = mp.size();

        for(auto it : mp)
        {
            int ele = it.first;
            nums.push_back(it.first);
            mp[ele]--;
        }

        for(auto it : mp)
        {
            int ele = it.first;
            while(mp[ele] > 0)
            {
                nums.push_back(ele);
                mp[ele]--;
            }
        }
        return ans;
    }
};
