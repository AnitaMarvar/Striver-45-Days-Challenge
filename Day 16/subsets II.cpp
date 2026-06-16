class Solution {
public:
    void solve(vector<int>& nums, int ind, vector<int>& level, vector<vector<int>>&ans)
    {
        if(ind==nums.size())
        {
            ans.push_back(level);
            return;
        }

        level.push_back(nums[ind]);
        solve(nums, ind+1, level, ans);

        level.pop_back();
        solve(nums, ind+1, level, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>>ans,res;
        vector<int>level;

        solve(nums, 0, level, ans);
        set<vector<int>>sets;
        for(auto it : ans)
        {
            sets.insert(it);
        }
        for(auto it : sets)
        {
            res.push_back(it);
        }
        return res;
        
    }
};
